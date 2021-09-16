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