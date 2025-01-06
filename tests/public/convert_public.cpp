#include "convert.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "ver.hpp"
#include "catch_amalgamated.hpp"

namespace {
TEST_CASE("AntToArt", "[convert-public]")
{
	std::unordered_set<std::string> words;	
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);

 	std::vector< std::string > r  = convert("ant", "art", words);

	std::ifstream in2("words.txt");
 	REQUIRE(r.size() == 2);
 	REQUIRE(  validConversion(r, "ant", "art", in2) );
}

TEST_CASE("AntToEat", "[convert-public]")
{
	std::unordered_set<std::string> words;
	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);

 	std::vector< std::string > r = convert("ant", "eat", words);

	std::ifstream in2("words.txt");

 	REQUIRE(r.size() == 5);
 	REQUIRE(  validConversion(r, "ant", "eat", in2) );
}

TEST_CASE("PuttersToHampers", "[convert-public]")
{
	std::unordered_set<std::string> words;
	std::string WORD_ONE = "putters";
	std::string WORD_TWO = "hampers";
	const unsigned CORRECT_LENGTH = 14;

	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	REQUIRE(r.size() == CORRECT_LENGTH);
 	REQUIRE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}

TEST_CASE("BankingToBrewing", "[convert-public]")
{
	std::unordered_set<std::string> words;
	std::string WORD_ONE = "banking";
	std::string WORD_TWO = "brewing";
	const unsigned CORRECT_LENGTH = 15;

	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	REQUIRE(r.size() == CORRECT_LENGTH);
 	REQUIRE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}

}