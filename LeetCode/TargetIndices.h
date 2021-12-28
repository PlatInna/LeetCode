#pragma once

#include<vector>
#include<algorithm>

//You are given a 0 - indexed integer array nums and a target element target.
//A target index is an index i such that nums[i] == target.
//Return a list of the target indices of nums after sorting nums in non - decreasing order.If there are no target indices, return an empty list.The returned list must be sorted in increasing order.

std::vector<int> targetIndices(std::vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    std::vector<int> res;
    int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    for (int i = l; i < r; i++) {
        res.push_back(i);
    }
    return res;
}