#pragma once
/*
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].
Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. 
Since the answer can be huge, return it modulo 10^9 + 7.

Example 1:
    Input: n = 3, k = 0
    Output: 1
    Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

Example 2:
    Input: n = 3, k = 1
    Output: 2
    Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

Let's say we have n=4 with k not fixed;
Now, see the steps
1 2 3 4 => k = 0
1 2 4 3 => k = 1
1 4 2 3 => k = 2
4 1 2 3 => k = 3
Thus we can observe tha whenever we shift a greater number towards left k increases
infact k = no. of shift of a greater number towards left + prev_count;
e.g shift 3 by two step left
4 3 1 2 => k = 2 + 3 = 5;
Now its clear that we are using prev calculations to get the curr ans, leading towards DP;
First look for 2D dp,
If n=0, no inverse pairs exist. Thus, dp[0][k]=0.
If k=0, only one arrangement is possible, which is all numbers sorted in ascending order. Thus, dp[n][0]=1.
Otherwise, dp[i,j] = sum( for(p=0 to min(j, i-1) dp[i-1][j-p] ) )
Now, in the 3rd step, in the loop every time we are just adding a value to right and removing a value from left
Thus our next optimization in this step =>
dp[i][j] = d[i][j-1] + (dp[i-1][j-1] - (i>=j ? dp[i-1][j-i] : 0));
Now we can do more optimization by the fact that we are using only two values from the prev row and thus need only prev row for calculations.
*/

#include<vector>

int kInversePairs(int n, int k) {
    std::vector<int> dp(k + 1, 0);
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        std::vector<int> tmp(k + 1, 0);
        tmp[0] = 1;
        for (int j = 1; j <= k; j++) {
            long long val = (dp[j] + mod - ((j - i) >= 0 ? dp[j - i] : 0)) % mod;
            tmp[j] = (tmp[j - 1] + val) % mod;
        }
        dp = tmp;
    }
    return (dp[k] + mod - (k > 0 ? dp[k - 1] : 0)) % mod;
}