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
//#include "kInversePairs.h"
//#include "BinarySearch.h"
//#include "mySqrt.h"
//#include "guessNumber.h"
//#include "RotatedSortedArray.h"
//#include "FirstBadVersion.h"
//#include "FindPeakElement.h"
#include "FindMinInRotatedSortedArray.h"


using namespace std;

void Test_0() {
    //int target = 1;
    auto expected = 0;
    std::vector<int> v = { 0 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_1() {
    auto expected = 0;
    std::vector<int> v = { 0,1 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_2() {
    auto expected = 0;
    std::vector<int> v = { 1,0 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_3() {
    auto expected = 0;
    std::vector<int> v = { 0,1,2 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_4() {
   auto expected = 0;
    std::vector<int> v = { 1,2,0 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_5() {
    auto expected = 0;
    std::vector<int> v = { 4,0,1,2 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_6() {
    auto expected = 0;
    std::vector<int> v = { 3,4,0,1 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_7() {
    auto expected = 0;
    std::vector<int> v = { 3,4,0,1,2 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_8() {
    auto expected = 0;
    std::vector<int> v = { 3,0,1,2 };
    ASSERT_EQUAL(findMin(v), expected);
}

void Test_9() {
    auto expected = 0;
    std::vector<int> v = { 2,0,1};
    ASSERT_EQUAL(findMin(v), expected);
}


int main() {
    LOG_DURATION("Total duration");

    TestRunner tr;
    {
        LOG_DURATION("duration");
        RUN_TEST(tr, Test_0);
        RUN_TEST(tr, Test_1);
        RUN_TEST(tr, Test_2);
        RUN_TEST(tr, Test_3);
        RUN_TEST(tr, Test_4);
        RUN_TEST(tr, Test_5);
        RUN_TEST(tr, Test_6);
        RUN_TEST(tr, Test_7);
        RUN_TEST(tr, Test_8);
        RUN_TEST(tr, Test_9);
    }    

    return 0;
}