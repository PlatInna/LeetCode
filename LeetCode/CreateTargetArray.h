#pragma once

#include<vector>

// Given two arrays of integers numsand index.Your task is to create target array under the following rules :
// Initially target array is empty.
// From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
// Repeat the previous step until there are no elements to read in numsand index.
// Return the target array.

std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
    std::vector<int> res;
    auto it = res.begin();
    for (int i = 0; i < nums.size(); i++) {
        it += index[i];
        res.insert(it, nums[i]);
        it = res.begin();
    }
    return res;
}

std::vector<int> createTargetArray_(std::vector<int>& nums, std::vector<int>& index) {
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++) 
        res.insert(res.begin() + index[i], nums[i]);
    return res;
}