#pragma once

#include<algorithm>
#include<vector>

// Given an integer array numsand an integer k, return the number of pairs(i, j) where i < j such that | nums[i] - nums[j]| == k.

int countKDifference(std::vector<int>& nums, int k) {
    int count = 0;
    if (nums.size() == 1)
        return count;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (abs(nums[i] - nums[j]) == k)
                count++;
        }
    }
    return count;
}