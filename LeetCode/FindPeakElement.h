#pragma once
#include <vector>

// Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞.
// You must write an algorithm that runs in O(log n) time.

int findPeakElement(std::vector<int>& nums) {
	int l = 0, r = nums.size() - 1, m = 0;
	if (r == 0) return 0;
	if (nums[0] > nums[1]) return 0; // check if we have peak at first pos
	if (nums[r - 1] < nums[r]) return r; // check if we have peak at last pos
	
	while (l < r) {
		m = l + (r - l) / 2;
		if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1]) return m;
		else if (nums[m] < nums[m + 1] && nums[m] > nums[m - 1]) l = m + 1; // check if we have descending segment in position m (from left to right)
		else r = m;
	}
	return l;
}