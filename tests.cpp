#include "catch.hpp"
#include "dsstring.h"
#include "dsvector.hpp"

using namespace std;

TEST_CASE("Updates to DSString") {

    DSString test[6] = {DSString("asdf"), DSString("CaPs"), DSString("thisisalongstring"), DSString("zhisisalongstring"), DSString(), DSString("ZaPs")};
    
    SECTION("Comparison Operators") {
        REQUIRE(test[0] > test[1]);
        REQUIRE(test[0] < test[2]);
        REQUIRE(test[2] < test[3]);
        REQUIRE(test[3] > test[2]);
        REQUIRE(test[2] > test[5]);
        REQUIRE(test[5] > test[1]);
        REQUIRE_FALSE(test[0] < test[0]);
    }
}
