#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace {
bool differByOne(const std::string &s1,
                 const std::string &s2) {
  if (s1.size() != s2.size()) {
    return false;
  }

  bool differByOne = false;
  for (unsigned i = 0; i < s1.size(); i++) {
    if (s1.at(i) != s2.at(i)) {
      if (differByOne) {
        return false;
      }

      differByOne = !differByOne;
    }
  }

  return differByOne;
}

void loadDictionaryFromStream(std::istream &in,
                              std::unordered_set<std::string> &words) {
  std::string line, word;
  std::stringstream ss;

  while (getline(in, line)) {
    ss.clear();
    ss << line;
    while (ss >> word) {
      words.insert(word);
    }
  }
}

} // namespace

bool validConversion(const std::vector<std::string> &r, std::string s1,
                     std::string s2, std::istream &in) {
  std::unordered_set<std::string> words;
  loadDictionaryFromStream(in, words);
  if (r.empty()) {
    return false;
  }
  if (r.at(0) != s1) {
    return false;
  } 

  if (r.at(r.size() - 1) != s2) {
    return false;
  }

  if (r.size() == 1) {
    return s1 == s2;
  }

  std::string prev = r.at(0);
  if (!words.count(prev)) {
    return false;
  }
  for (std::string word : std::vector<std::string>(r.begin()+1, r.end())) {
    if (!differByOne(prev, word) || !words.count(word)) return false;
    prev = word;
  }
  return true;
}