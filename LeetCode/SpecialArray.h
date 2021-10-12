#pragma once

// given an array nums of non - negative integers.nums is considered special if there exists a number x 
// such that there are exactly x numbers in nums that are greater than or equal to x.
// Notice that x does not have to be an element in nums.
// Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

#include<algorithm>
#include<vector>

int specialArray(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	int size = nums.size();
	for (int x = 0; x <= size; x++) {
		int lo = 0, mid = 0, hi = size - 1, pos = 0;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (nums[mid] < x) {
				lo = mid + 1;
			}
			else
				hi = mid - 1;
		}
		pos = hi;
		if (x == size - 1 - pos) 
			return x;
	}
	return - 1;
}