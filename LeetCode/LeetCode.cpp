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
//#include "MyPow.h"
//#include "FindMinInRotatedSortedArray2.h"
//#include "IntersectionTwoArrays.h"
//#include "TwoSum.h"
//#include "FindDuplicate.h"
//#include "CountNegatives.h"
//#include "kWeakestRows.h"
//#include "PeakIndexInMountainArray.h"
//#include "DistanceBetweenTwoArrays.h"
//#include "SpecialArray.h"
#include "FairCandySwap.h"
#include "KthMissingPositiveNumber.h"

using namespace std;

void Test_0() {
    //int target = 3;
    std::vector<int> expected = { 2,3 };
    vector<int> alice = { 2 };
    vector<int> bob = { 1,3 };
    ASSERT_EQUAL(fairCandySwap(alice, bob), expected);
}

void Test_1() {
    std::vector<int> expected = { 2,1 };
    vector<int> alice = { 9, 2 };
    vector<int> bob = { 1,8};
    ASSERT_EQUAL(fairCandySwap(alice, bob), expected);
}

void Test_2() {
   std::vector<int> expected = { 1,2 };
    vector<int> alice = { 1,1 };
    vector<int> bob = { 2,2 };
    ASSERT_EQUAL(fairCandySwap(alice, bob), expected);
}

void Test_3() {
    std::vector<int> expected = { 1,2 };
    vector<int> alice = { 1,2 };
    vector<int> bob = { 2,3 };
    ASSERT_EQUAL(fairCandySwap(alice, bob), expected);
}

void Test_4() {
    std::vector<int> expected = { 5, 4 };
    vector<int> alice = { 1,2,5 };
    vector<int> bob = { 2,4 };
    ASSERT_EQUAL(fairCandySwap(alice, bob), expected);
}

void Test_5() {
   std::vector<int> expected = { 3,1 };
    vector<int> alice = { 3, 2, 1,};
    vector<int> bob = { 1,1 };
    ASSERT_EQUAL(fairCandySwap(alice, bob), expected);
}
/*
void Test_6() {
    std::vector<int> expected = { -9,-9,2,2,2,2,2,2,7 };
    std::vector<int> v1 = { 1,2,2,2,-9,2,2,2,2,-1,-1,-1,-9,777,7 };
    std::vector<int> v2 = { 2,2,2,2,0,-9,-9,-9,7,7,7,4,-2,2,2,-3,0,0 };
    ASSERT_EQUAL(intersection(v1, v2), expected);
}

void Test_7() {
    std::vector<int> expected = { 1 };
    std::vector<int> v1 = { 1 };
    std::vector<int> v2 = { 1 };
    ASSERT_EQUAL(intersection(v1, v2), expected);
}

void Test_8() {
    auto expected = -1;
    std::vector<int> v = {2,2,3,-1,1,2,2};
    ASSERT_EQUAL(findMin(v), expected);
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
    float x, y;
    x = 0.0;
    y = 1.0 / x; // y = inf type of?
    //cout << y << '\t' << 3 * 3 % 5 << '\t' << 3 * 3 / 5 << endl ;
    vector<int> v = { 1,3,5,6,7,8,11,13,14,16,17,18,19,20,21,23,24,25,26,28,29,30,31,34,35,36,37,38,41,43,44,47,50,51,53,54,56,57,58,59,60,62,63,65,67,68,
        69,70,71,72,73,74,76,78,80,81,83,84,85,88,89,90,91,92,93,95,97,98,102,103,104,105,108,109,110,111,112,113,114,117,120,123,124,125,127,
        128,129,130,131,132,133,135,136,137,138,139,141,142,145,146,148,149,150,151,153,154,155,156,161,162,164,167,168,169,170,171,172,175,
        176,178,179,181,182,184,191,193,195,196,199,201,202,204,205,208,210,214,215,217,219,221,222,224,226,228,229,230,231,232,234,235,236,
        240,242,246,248,249,251,252,253,254,255,256,257,258,259,260,261,262,265,267,269,272,273,275,278,279,280,281,282,283,284,285,286,287,
        289,291,292,293,296,297,298,299,303,305,306,308,312,313,315,316,318,320,323,324,327,330,332,335,337,340,342,343,344,346,349,350,352,
        353,354,356,357,359,360,362,366,367,369,370,374,375,376,377,378,379,382,384,386,390,392,393,394,395,396,399,400,401,403,406,411,413,
        415,416,420,424,425,426,427,429,430,432,434,435,436,437,438,439,440,441,442,443,444,446,447,448,449,452,455,456,458,459,460,461,462,
        463,464,465,466,467,469,470,471,472,477,479,480,483,484,486,488,489,490,491,492,493,494,495,500,501,503,504,506,508,510,513,514,515,
        516,517,527,531,533,534,535,536,542,543,546,547,548,549,550,553,556,559,561,562,563,566,567,569,571,572,576,578,579,581,582,583,584,
        586,589,591,592,593,594,595,598,600,601,602,603,605,606,607,609,611,612,613,614,616,617,621,622,624,625,626,627,630,631,633,635,636,
        637,639,640,643,644,646,647,648,649,650,651,652,654,658,660,661,662,663,664,665,667,668,669,672,673,678,679,683,685,686,687,689,690,
        691,692,693,695,696,697,701,702,703,704,707,709,711,714,717,718,719,720,721,723,724,725,726,728,729,730,733,735,736,737,738,740,742,
        745,746,747,750,754,755,757,759,761,763,765,768,771,773,774,775,776,779,780,781,782,783,784,787,788,789,790,791,792,794,795,797,798,
        800,801,805,806,808,810,811,812,814,816,819,822,824,825,826,828,831,833,835,838,841,842,844,845,846,847,849,853,854,855,857,858,861,
        862,866,868,869,870,874,878,882,884,885,888,889,890,892,893,897,900,903,905,906,907,908,911,913,916,918,920,921,922,924,925,926,928,
        929,930,932,933,934,936,937,938,940,942,944,946,949,953,954,956,957,958,961,962,964,965,966,969,972,973,974,976,977,978,979,980,981,
        982,984,985,986,988,993,996,997,999 };
    cout << findKthPositive(v, 724) << endl;

    LOG_DURATION("Total duration");

    TestRunner tr;
    {
        LOG_DURATION("duration");
        //RUN_TEST(tr, Test_0);
        //RUN_TEST(tr, Test_1);
        //RUN_TEST(tr, Test_2);
        //RUN_TEST(tr, Test_3);
        //RUN_TEST(tr, Test_4);
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