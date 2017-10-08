#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "dsvector.hpp"
#include "dsstring.h"
#include "sortmanager.h"

using namespace std;

int runCatchTests(int argc, char* argv[]) {
    return Catch::Session().run();
}

int main(int argc, char *argv[])
{

    if(DSString(argv[1]) == DSString("-t")) {
        runCatchTests(argc, argv);
        return 0;
    }

    SortManager(argv[1], argv[2]).runSortingCompetition();

}
