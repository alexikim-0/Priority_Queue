#include "convert.hpp"
#include "MyPriorityQueue.hpp"
#include "catch_amalgamated.hpp"
#include "ver.hpp"
#include <fstream>

namespace {

TEST_CASE("PutterToHammer", "[convert-custom]")
{
	std::unordered_set<std::string> words;
	std::string WORD_ONE = "putter";
	std::string WORD_TWO = "hammer";

	std::ifstream in("words.txt");
	loadWordsIntoTable(words, in);


 	std::vector< std::string > r = convert(WORD_ONE, WORD_TWO, words);

	std::ifstream in2("words.txt");

 	REQUIRE(  validConversion(r, WORD_ONE, WORD_TWO, in2) );
}

}