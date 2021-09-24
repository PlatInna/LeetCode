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
//#include "FindMinInRotatedSortedArray.h"
//#include "SearchForRange.h"
//#include "FindClosestElements.h"
//#include "FindClosestElements.h"
#include "PerfectSquare.h"

using namespace std;

void Test_0() {
    int target = 16;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_1() {
    int target = 15;
    auto expected = false;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_2() {
    int target = 17;
    auto expected = false;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_3() {
    int target = 4;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_4() {
    int target = 9;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_5() {
    int target = 25;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_6() {
    int target = 36;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_7() {
    int target = 49;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_8() {
    int target = 64;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
}

void Test_9() {
    int target = 81;
    auto expected = true;
    //std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(isPerfectSquare(target), expected);
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