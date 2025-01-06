#include <vector>
#include "ver.hpp"
#include "MyPriorityQueue.hpp"
#include "catch_amalgamated.hpp"

namespace{


TEST_CASE("BasicInsert", "[pq-public]")
{
	MyPriorityQueue<int> mpq;
	mpq.insert(3);
	REQUIRE(mpq.min() == 3);
}


TEST_CASE("BasicMin", "[pq-public]")
{
	MyPriorityQueue<int> mpq;
	mpq.insert(3);
	mpq.insert(5);
	REQUIRE(mpq.min() == 3);
}


TEST_CASE("BasicExtract", "[pq-public]")
{
	MyPriorityQueue<int> mpq;
	mpq.insert(3);
	mpq.insert(2);
    mpq.extractMin();
	REQUIRE(mpq.min() == 3);
}

}