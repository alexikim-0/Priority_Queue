#include "convert.hpp"
#include "MyPriorityQueue.hpp"
#include <string>
#include <sstream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <iostream>
using namespace std;

struct object_struct {
	std::string word;
	int heuristic_value;
	std::vector < std::string > full_path;

	object_struct(const string& w, int val, const vector< string >& fp)
		: word(w)
		, heuristic_value(val)
		, full_path(fp)
	{}

	bool operator<(const object_struct& other) {
		if (heuristic_value == other.heuristic_value) {
			if (full_path.size() < other.full_path.size()) {
				return true;
			} else {
				return false;
			}
		}
		if (heuristic_value < other.heuristic_value) {
			return true;
		} else {
			return false;
		}
	}
};

// You should not need to change this function.
void loadWordsIntoTable(std::unordered_set<std::string> & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}

}

int calculate_heuristic(const string& current, const string& s2, const vector< string >& path) {
	int heuristic = path.size();
	for (long unsigned int i = 0; i < current.length(); ++i) {
		if (current[i] != s2[i]) {
			++heuristic;
		}
	}
	return heuristic;
}


std::vector< std::string > convert(const std::string & s1, const std::string & s2, const std::unordered_set<std::string> & words)
{
	if (s1 == s2) {
		return {s1};
	} else if (s1.length() != s2.length()) {
		return {};
	}
	std::string word_final = s1;
	std::unordered_set< string > visited_words;
	MyPriorityQueue< object_struct > queue;
	int initial_heuristic = 0;
	for (long unsigned i = 0; i < s1.length(); ++i) {
		if (s1[i] != s2[1]) {
			++initial_heuristic;
		}
	}
	queue.insert(object_struct{s1, initial_heuristic, {s1}});
	visited_words.insert(s1);

	while (!queue.isEmpty()) {
		object_struct current_object = queue.min();
		word_final = current_object.word;
		if (!queue.isEmpty() && queue.min().heuristic_value < 0) {
			std::cout << "PROBLEM";
		}
		queue.extractMin();

		if (word_final == s2) {
			return current_object.full_path;
		}
		
		
		std::string word_cpy = word_final;
		char c = 'a';
		for (long unsigned int i = 0; i < s1.length(); ++i) {
			for (int j = 0; j < 26; ++j) {
				word_final[i] = static_cast<char>(c + j);
				if (words.find(word_final) != words.end() && visited_words.find(word_final) == visited_words.end()) {
					visited_words.insert(current_object.word);
					vector< string > new_path = current_object.full_path;
					new_path.push_back(word_final);
					int new_heuristic = calculate_heuristic(word_final, s2, new_path);
					queue.insert(object_struct{word_final, new_heuristic, new_path});
				}
			}
			word_final = word_cpy;
		}

	}
	return {}; 
}

