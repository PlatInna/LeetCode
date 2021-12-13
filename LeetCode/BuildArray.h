#pragma once
#include<vector>

std::vector<int> buildArray(std::vector<int>& nums) {
    std::vector<int> ans = nums;
    for (int i = 0; i < nums.size(); i++) {
        ans[i] = nums[nums[i]];;
    }
    return ans;
}
