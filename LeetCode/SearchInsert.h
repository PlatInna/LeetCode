#pragma once

// Given a sorted array of distinct integersand a target value, return the index if the target is found.If not, return the index where 
// it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

#include<vector>

int searchInsert(std::vector<int>& nums, int target) {
	int low = 0, mid = 0, hi = nums.size() - 1;
	while (low <= hi){
		mid = low + (hi - low) / 2;
		if (nums[mid] < target) {
			low = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return low;
}