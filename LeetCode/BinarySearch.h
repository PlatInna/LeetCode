#pragma once
#include <vector>

int search(std::vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;
	int m = 0;

	while (r - l > 1) {
		m = l + (r - l) / 2; // prevent r + l overflow
		//m = (l + r) / 2;
		//if (nums[m] < target) // leftside binary search gives min i from right part
		if ( nums[m] <= target) // rightside binary search gives max i from left part
			l = m;
		else {
			r = m;
		}
	}

	if (nums[r] != target) {
		if (nums[l] != target)
			return -1;
		else
			return l;
	}
	else {
		return r;
	}
}


// Template #1 is used to search for an element or condition which can be determined by accessing a single index in the array.
// Using closed interval [left, right]
int binarySearch_1(std::vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) { return mid; }
		else if (nums[mid] < target) { left = mid + 1; }
		else { right = mid - 1; }
	}

	// End Condition: left > right
	return -1;
}
