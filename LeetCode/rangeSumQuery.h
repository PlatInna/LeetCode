#pragma once
/*
Given an integer array nums, handle multiple queries of the following types:
    - Update the value of an element in nums.
    - Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:
    - NumArray(int[] nums) Initializes the object with the integer array nums.
    - void update(int index, int val) Updates the value of nums[index] to be val.
    - int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive 
      (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
Example 1:
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]
Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
*/

#include <vector>
#include <numeric>

class NumArray {
public:
    NumArray(std::vector<int>& nums) : data(nums) {
        sumed.resize(data.size());
        sumed[0] = data[0];
        for (int i = 1; i < nums.size(); i++) {
            sumed[i] = sumed[i - 1] + data[i];
        }
    }

    void update(int index, int val) {
        int dif = val - data[index];
        //data[index] = val;
        mdif[index] = dif;
    }

    int sumRange(int left, int right) {
        //int sum = 0;
        //for (int i = left; i <= right; i++) {
        //    sum += data[i];
        //}
        //if (right - left < 1000) {
        //    return std::accumulate(data.begin() + left, data.begin() + right + 1, 0);
        //} 
        //int mid = (right - left) / 2;
        //future<int> f = std::async([this, left, right, mid] {return std::accumulate(this->data.begin() + left + mid + 1, this->data.begin() + right + 1, 0); });
        //int sum = sumRange(left, mid);
        //return sum + f.get();
        int total_dif = 0;
        if (!mdif.empty()) {
            auto l_it = mdif.lower_bound(left);
            auto r_it = mdif.upper_bound(right);
            for (auto i = l_it; i != r_it; i++) {
                total_dif += i->second;
            }
        }

        if (left > 0) {
            return sumed[right] - sumed[left - 1] + total_dif;
        }
        else {
            return sumed[right] + total_dif;
        }
    }

private:
    std::vector<int> data, sumed;
    std::map<int, int> mdif;
};