// LeetCode.cpp 
//

#include <iostream>
#include <vector>

#include "profile.h"
#include "test_runner.h"

//#include "minRefuelStops.h"
//#include "palindromePairs.h"
//#include "isSumEqual.h"
//#include "maximumUnits.h"
//#include "generateParenthesis.h"
//#include "rangeSumQuery.h"
#include "kInversePairs.h"


using namespace std;

void Test_1() {
    auto expected = 0;
    ASSERT_EQUAL(kInversePairs(4, 0), expected);
}

void Test_2() {

}

int main() {
    LOG_DURATION("Total duration");

    TestRunner tr;
    {
        LOG_DURATION("duration Test_1");
        RUN_TEST(tr, Test_2);
    }
    

    auto res = 0;

    return 0;
}