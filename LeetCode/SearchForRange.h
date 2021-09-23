#pragma once
#include <vector>
#include <iostream>



std::vector<int> searchRange(std::vector<int>& nums, int target) {

	std::vector<int> res = { -1, -1 };

	if (nums.size() == 0) return res;

	int l = 0, r = nums.size() - 1, m = 0; // to find left bound
		while (r - l > 1) {
		m = l + (r - l) / 2;
		if (nums[m] < target) l = m;
		else r = m;
	}
	if (nums[r] == target) res[0] = r;
	if (nums[l] == target) res[0] = l;

	l = 0, r = nums.size() - 1, m = 0; // to find right bound
		while (r - l > 1) {
		m = l + (r - l) / 2;
		if (nums[m] <= target) l = m;
		else r = m;
	}
	if (nums[l] == target) res[1] = l;
	if (nums[r] == target) res[1] = r;

	//for (int el : nums) {
	//	std::cout << el << ' ';
	//}
	//std::cout << '\n';
	//std::cout << '[' << res[0] << ',' << res[1] << ']' << '\n';

	return res;
}

