#pragma once

#include <vector>
#include <algorithm>

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may 
// return the result in any order.

vector<int> binary_searchShortInLong(vector<int>& sh, vector<int>& lg) {
	int l = 0, r = lg.size() - 1, m = 0;
	std::vector<int> res;

	for (int i = 0; i < sh.size(); i++) {
		if (i > 0 && sh[i] != sh[i - 1] || i == 0) {
			while (r - l > 1) {
				m = l + (r - l) / 2;
				if (lg[m] <= sh[i])
					l = m;
				else
					r = m;
			}
			if (lg[r] == sh[i])	res.push_back(sh[i]);
			else if (lg[l] == sh[i]) res.push_back(sh[i]);
			l = 0, r = lg.size() - 1, m = 0;
		}
	}

	return res;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	std::vector<int> res;

	if (nums1.size() == 0 || nums2.size() == 0) return res;
	if (nums1.size() == 1 && nums2.size() == 1 && nums1[0] != nums2[0]) return res;
	if (nums1.size() == 1 && nums2.size() == 1 && nums1[0] == nums2[0]) return nums1;

	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());

	// using Binary Search of an element from shorter vector in a longer vector if possible
	if (nums1.size() > nums2.size())
		return binary_searchShortInLong(nums2, nums1);
	else
		return binary_searchShortInLong(nums1, nums2);
}