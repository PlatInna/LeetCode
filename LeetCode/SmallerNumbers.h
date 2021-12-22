#pragma once

//Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
//Return the answer in an array.

#include<vector>

std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    std::vector<int> res;
    int count;
    for (int i = 0; i < nums.size(); i++) {
        count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < nums[i])
                count++;
        }
        res.push_back(count);
    }
    return res;
}