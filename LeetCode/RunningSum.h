#pragma once

//Given an array nums.We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

#include<vector>

std::vector<int> runningSum(std::vector<int>& nums) {
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0)
            res.push_back(nums[i]);
        else
            res.push_back(res[i - 1] + nums[i]);
    }
    return res;
}