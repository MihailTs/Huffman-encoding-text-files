#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../CommandProcessing.h"
#include <string>

TEST_CASE("testStripFunction"){
    std::string str = "  name";
    CHECK(strip(str) == "name");
    str = "     name ";
    CHECK(strip(str) == "name");
    str = "name";
    CHECK(strip(str) == "name");
}