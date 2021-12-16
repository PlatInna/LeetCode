#pragma once

// Given the array nums consisting of 2n elements in the form[x1, x2, ..., xn, y1, y2, ..., yn].
// Return the array in the form[x1, y1, x2, y2, ..., xn, yn].

#include<vector>

std::vector<int> shuffle(std::vector<int>& nums, int n) {
    std::vector<int> res;
    for (int i = 0; i < nums.size() / 2; i++) {
        res.push_back(nums[i]);
        res.push_back(nums[i + n]);
    }
    return res;
}