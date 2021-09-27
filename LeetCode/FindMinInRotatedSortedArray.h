#pragma once
#include <iostream>
#include <vector>

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

int findMin(std::vector<int>& nums) {
	int l = 0, r = nums.size(), m = 0;
	if (r == 1) return nums[0];
	if (nums[r-1] > nums[0]) return nums[0]; // check if pivot index == 0
	if (nums[0] > nums[1]) return nums[1]; // check if pivot index == 1

	while (l < r) {
		m = l + (r - l) / 2;
		if (m == 0 && nums[m] > nums[m+1]) return nums[m+1];
		if (m > 0 and m < r and nums[m] > nums[m - 1] and nums[m] > nums[m + 1]) return nums[m+1];
		else if (nums[l] > nums[m]) r = m;
		else l = m + 1;
	}
	std::cout << "==== ERROR ====" << '\n';
	return 0; 
}