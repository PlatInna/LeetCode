#pragma once

// You have n coinsand you want to build a staircase with these coins.The staircase consists of k rows where the ith row has exactly i coins.
// The last row of the staircase may be incomplete.
// Given the integer n, return the number of complete rows of the staircase you will build.

// Find the maximum k such that k * (k + 1) / 2 <= n



int exhaustiveIteration(int n) {
    int row = 0, sum = 0;
    while (n > (sum + row)) {
        row++;
        sum = sum + row;
    }
    return row;
}

int arrangeCoins(int n) {
    int lo = 0, hi = n;
    double mid, k;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        k = mid * (mid + 1) / 2;
        if (k == n)
            return (int)mid;
        if (k > n)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return hi;
	
}

// Approach 2: Math - completing the square technique.
// int arrangeCoins(int n) {
//     return (int)(std::sqrt(2 * (double)n + 0.25) - 0.5);
// }