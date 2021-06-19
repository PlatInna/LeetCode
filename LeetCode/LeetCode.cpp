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
#include "rangeSumQuery.h"


using namespace std;

void Test_1() {
    vector<int> v = { 1, 3, 5 };
    NumArray numArray(v);
    auto expected = 9;
    ASSERT_EQUAL(numArray.sumRange(0, 2), expected);
    numArray.update(1, 2);   // nums = [1, 2, 5]
    expected = 8;
    ASSERT_EQUAL(numArray.sumRange(0, 2), expected);
}

void Test_2() {
    vector<int> v = { 7, 2, 7, 2, 0 };
    NumArray numArray(v);
    auto expected = 18;
    ASSERT_EQUAL(numArray.sumRange(0, 4), expected);
    numArray.update(4, 6);   // nums = { 7, 2, 7, 2, 6 }
    numArray.update(0, 2);   // nums = { 2, 2, 7, 2, 6 }
    numArray.update(0, 9);   // nums = { 9, 2, 7, 2, 6 }
    expected = 6;
    ASSERT_EQUAL(numArray.sumRange(4, 4), expected);
    numArray.update(3, 8);   // nums = { 9, 2, 7, 8, 6 }
    expected = 32;
    ASSERT_EQUAL(numArray.sumRange(0, 4), expected);
    numArray.update(4, 1);   // nums = { 9, 2, 7, 8, 1 }
    expected = 26;
    ASSERT_EQUAL(numArray.sumRange(0, 3), expected);
    expected = 27;
    ASSERT_EQUAL(numArray.sumRange(0, 4), expected);

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