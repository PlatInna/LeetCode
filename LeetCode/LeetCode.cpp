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
//#include "PerfectSquare.h"
//#include "NextGreatestLetter.h"
#include "MyPow.h"

using namespace std;

void Test_0() {
    double target = -2;
    int n = 0;
    double expected = 1;
    //std::vector<char> v = {'c','e'};
    ASSERT_EQUAL(myPow(target, n), expected);
}

void Test_1() {
    double target = -2;
    int n = 1;
    double expected = -2;
    //std::vector<char> v = {'c','e'};
    ASSERT_EQUAL(myPow(target, n), expected);
}

void Test_2() {
    double target = -2;
    int n = 2;
    double expected = 4;
    //std::vector<char> v = {'c','e'};
    ASSERT_EQUAL(myPow(target, n), expected);
}

void Test_3() {
    double target = -2;
    int n = -1;
    double expected = -0.5;
    //std::vector<char> v = {'c','e'};
    ASSERT_EQUAL(myPow(target, n), expected);
}

void Test_4() {
    double target = -2;
    int n = -2;
    double expected = 0.25;
    //std::vector<char> v = {'c','e'};
    ASSERT_EQUAL(myPow(target, n), expected);
}
/*
void Test_5() {
    char target = 'f';
    auto expected = 'c';
    std::vector<char> v = { 'c','e' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_6() {
    char target = 'g';
    auto expected = 'c';
    std::vector<char> v = { 'c','e' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_7() {
    char target = 'z';
    auto expected = 'c';
    std::vector<char> v = { 'c','e' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_8() {
    char target = 'f';
    auto expected = 'g';
    std::vector<char> v = { 'c','e','f','g' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_9() {
    char target = 'g';
    auto expected = 'c';
    std::vector<char> v = { 'c','e','f','g' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_10() {
    char target = 'd';
    auto expected = 'e';
    std::vector<char> v = { 'c','e','f','g' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_11() {
    char target = 'b';
    auto expected = 'c';
    std::vector<char> v = { 'c','e','f','g' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_12() {
    char target = 'j';
    auto expected = 'c';
    std::vector<char> v = { 'c','e','f','g' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_13() {
    char target = 'a';
    auto expected = 'c';
    std::vector<char> v = { 'c','e','f','g' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_14() {
    char target = 'z';
    auto expected = 'c';
    std::vector<char> v = { 'c','e','f','g' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_15() {
    char target = 'e';
    auto expected = 'f';
    std::vector<char> v = { 'c','e','e','e','e','f','f','f','g','g','g','y' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_16() {
    char target = 'f';
    auto expected = 'g';
    std::vector<char> v = { 'c','e','e','e','e','f','f','f','g','g','g','y'};
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_17() {
    char target = 'd';
    auto expected = 'e';
    std::vector<char> v = { 'c','e','e','e','e','f','f','f','g','g','g','g','g','y' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_18() {
    char target = 'd';
    auto expected = 'e';
    std::vector<char> v = { 'c','e','e','e','e','f','f','f','g','g','g','g','g','y' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

void Test_19() {
    char target = 'g';
    auto expected = 'j';
    std::vector<char> v = { 'c','f','j' };
    ASSERT_EQUAL(nextGreatestLetter(v, target), expected);
}

*/

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
        //RUN_TEST(tr, Test_5);
        //RUN_TEST(tr, Test_6);
        //RUN_TEST(tr, Test_7);
        //RUN_TEST(tr, Test_8);
        //RUN_TEST(tr, Test_9);
        //RUN_TEST(tr, Test_10);
        //RUN_TEST(tr, Test_11);
        //RUN_TEST(tr, Test_12);
        //RUN_TEST(tr, Test_13);
        //RUN_TEST(tr, Test_14);
        //RUN_TEST(tr, Test_15);
        //RUN_TEST(tr, Test_16);
        //RUN_TEST(tr, Test_17);
        //RUN_TEST(tr, Test_18);
        //RUN_TEST(tr, Test_19);
    }    

    return 0;
}