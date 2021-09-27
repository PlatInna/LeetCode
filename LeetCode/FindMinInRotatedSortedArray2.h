#pragma once

#include <iostream>
#include <vector>

// Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
// You must decrease the overall operation steps as much as possible.

int findMin(std::vector<int>& nums) {
	int l = 0, r = nums.size() - 1, m = 0;
	if (r == 0) return nums[0];
	if (nums[r] > nums[0]) return nums[0]; // check if pivot index == 0
	if (nums[0] > nums[1]) return nums[1]; // check if pivot index == 1

	while (l < r) {
		m = l + (r - l) / 2;
		if (nums[m] > nums[r])
			l = m + 1;
		else if (nums[m] < nums[r])
			r = m;
		else if (nums[m] == nums[r])
			r--;
	}
	return nums[l];
}