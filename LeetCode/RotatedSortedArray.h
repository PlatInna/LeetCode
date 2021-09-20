#pragma once
#include <vector>

int searchInSegment(std::vector<int>& nums, int l, int r, int target) {
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

// find position of max element using recursive binary search 
int findMax(std::vector<int>& v, int l, int r) { 

	if (l == r) return l;
	int m = l + (r - l) / 2;
	if (m == 0 and v[m] > v[m+1]) return m;
	if (m > 0 and m < r and v[m] > v[m - 1] and v[m] > v[m + 1]) return m;

	if (v[l] > v[m]) 
		return findMax(v, l, m - 1);
	else 
		return findMax(v, m + 1, r);
}

int search(std::vector<int>& nums, int target) {
	 
	int l1 = 0, r1 = 0, l2 = 0, r2 = nums.size() - 1;
	if (nums.size() == 1) {
		if (nums[0] == target) return 0;
		else return -1;
	}

	int max_el_pos = findMax(nums, l2, r2);

	if (max_el_pos == r2) 
		r1 = r2; // pivot index == 0
	else {
		l2 = max_el_pos + 1;
		r1 = max_el_pos;
	}

	if (target < nums[0]) {
		return searchInSegment(nums, l2, r2, target);
	}
	else {
		return searchInSegment(nums, l1, r1, target);
	}
}
