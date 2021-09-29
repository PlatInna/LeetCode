#pragma once

#include <vector>
#include <algorithm>

// Problem # 1 Intersection of Two Arrays 
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may 
// return the result in any order.

// Problem # 2 Intersection of Two Arrays II
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times 
// as it shows in both arrays and you may return the result in any order. 
// Added three functions: rightsideBinarySearch(), leftsideBinarySearch() and addElemsToVector()

int rightsideBinarySearch(const std::vector<int>& v, int key) {
	int l = 0, r = v.size() - 1, m = 0;
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (v[m] <= key)
			l = m;
		else
			r = m;
	}
	//std::cout << "rightsideBinarySearch: r = " << r << '\t' << "l = " << l << '\t' << "return r first" << '\n';
	if (v[r] == key) return r;
	else return l;
}

int leftsideBinarySearch(const std::vector<int>& v, int key) {
	int l = 0, r = v.size() - 1, m = 0;
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (v[m] < key)
			l = m;
		else
			r = m;
	}
	//std::cout << "leftsideBinarySearch: r = " << r << '\t' << "l = " << l << '\t' << "return l first" << '\n';
	if (v[l] == key) return l;
	else return r;
}

void addElemsToVector(std::vector<int>& res, const std::vector<int>& sh, const std::vector<int>& lg, int idx) {
	int a_sh = idx;
	int b_sh = rightsideBinarySearch(sh, sh[idx]);
	int a_lg = leftsideBinarySearch(lg, sh[idx]);
	int b_lg = rightsideBinarySearch(lg, sh[idx]);
	int min_qty = (b_sh - a_sh) > (b_lg - a_lg) ? (b_lg - a_lg + 1) : (b_sh - a_sh + 1);
	for (int j = 0; j < min_qty; j++) {
		res.push_back(sh[idx]);
	}
}

std::vector<int> binary_searchShortInLong(const std::vector<int>& sh, const std::vector<int>& lg) {
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
			if (lg[r] == sh[i]) {
				addElemsToVector(res, sh, lg, i);
			}
			else if (lg[l] == sh[i]) {
				addElemsToVector(res, sh, lg, i);
			}
			l = 0, r = lg.size() - 1, m = 0;
		}
	}

	return res;
}

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
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