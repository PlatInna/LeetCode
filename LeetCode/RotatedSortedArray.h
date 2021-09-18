#pragma once
#include <vector>

int searchInSegment(vector<int>& nums, int l, int r, int target) {
	int m = 0;
	if (l == r) {
		if (nums[l] == target) return l;
		else return -1;
	}
	else {
		while (l <= r) {
			m = l + (r - l) / 2;
			if (nums[m] == target) return m;
			if (nums[m] < target) l = m + 1;
			else r = m - 1;
		}
		return -1;
	}
}

int search(vector<int>& nums, int target) {
	int l1 = 0, r1 = 0, l2 = 0, r2 = nums.size() - 1;
	if (nums.size() == 1) {
		if (nums[0] == target) return 0;
		else return -1;
	}

	for (size_t i = 1; i < nums.size(); i++) { // determine r1 and l2;
		if (nums[i-1] > nums[i]) {
			r1 = i - 1;
			l2 = i;
		}
	}

	if (l2 == 0) r1 = r2; // if pivot index == 0;

	if (target < nums[0]) {
		return searchInSegment(nums, l2, r2, target);
	}
	else {
		return searchInSegment(nums, l1, r1, target);
	}

}
