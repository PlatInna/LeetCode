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
#include "FindClosestElements.h"

using namespace std;

void Test_0() {
    int target = -1, k = 6;
    std::vector<int> expected = { 0,1,1,1,3,4 };
    std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_1() {
    int target = 10, k = 6;
    std::vector<int> expected = { 1,1,1,3,4,4 };
    std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_2() {
    int target = 10, k = 1;
    std::vector<int> expected = {0};
    std::vector<int> v = {0};
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_3() {
    int target = 3, k = 4;
    std::vector<int> expected = { 1,3,4,4};
    std::vector<int> v = { 0,1,1,1,3,4,4 };
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_4() {
    int target = 2, k = 4;
    std::vector<int> expected = { 0,1,1,3};
    std::vector<int> v = { 0,0,1,1,3,4,4,4};
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_5() {
    int target = 4, k = 4;
    std::vector<int> expected = { 1,3,4,4 };
    std::vector<int> v = { 0,1,1,1,3,4,4};
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_6() {
    int target = 3, k = 5;
    std::vector<int> expected = { 3,3,3,3,4 };
    std::vector<int> v = { 0,1,1,1,3,3,3,3,4,4 };
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_7() {
    int target = 2, k = 8;
    std::vector<int> expected = { -1,0,1,1,1,3,3,8 };
    std::vector<int> v = { -10,-1,0,1,1,1,3,3,8,8,9 };
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_8() {
    int target = 2, k = 8;
    std::vector<int> expected = { -2,-1,0,1,1,1,3,3 };
    std::vector<int> v = { -4,-2,-1,0,1,1,1,3,3,8,8,9 };
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
}

void Test_9() {
    int target = 2, k = 8;
    std::vector<int> expected = { 0,1,1,1,3,3,8,8 };
    std::vector<int> v = { 0,1,1,1,3,3,8,8,9 };
    ASSERT_EQUAL(findClosestElements(v, k, target), expected);
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