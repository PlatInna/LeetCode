#pragma once

// Given an array of integers nums containing n + 1 integers where each integer is in the range[1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Approach 5: Binary Search

#include<vector>

int countMid(int m, std::vector<int>& nums) {
	int counter = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] <= m) {
			counter++;
		}
	}
	return counter;
}

int findDuplicate(std::vector<int>& nums) {
	// let's see on sorted arr [1,nums] - we can say
	// for each not duplicate element the count of numbers are less than or equal to it in the given array not more than element itself,
	// otherwise it is duplicate.
	int lo = 1, mid = 0, hi = nums.size();
	int duplicate = 0;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (mid < countMid(mid, nums)) {
			hi = mid - 1;
			duplicate = mid;
		}
		else
			lo = mid + 1;
	}
	return duplicate;
}
