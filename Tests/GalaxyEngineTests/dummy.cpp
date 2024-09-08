#include <catch2/catch_all.hpp>

int add(int a, int b)
{
    return a + b;
}

TEST_CASE("Check if tests are working", "[check]")
{
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-1, 1) == 0);
}