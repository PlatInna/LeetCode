#pragma once
#include <vector>

bool RSBS(int mid, int target) {
	return mid <= target;
}

bool LSBS(int mid, int target) {
	return mid < target;
}

void rightsideBinarySearch(const std::vector<int>& v, int target) {
	int lo = 0, hi = v.size() - 1, mid = 0;
	while (hi - lo > 1) {
		mid = lo + (hi - lo) / 2;
		if (v[mid] <= target)
			lo = mid;
		else
			hi = mid;
	}
	std::cout << " target = " << target << '\t' << "RSBS: lo = " << lo << '\t' << "mid = " << mid << '\t' << "hi = " << hi << '\n';

	//return r;

	/*if (v[hi] == target) {
		return hi;
		std::cout << "=============================================" << endl;
	}
	else return lo;
	*/
}

void leftsideBinarySearch(const std::vector<int>& v, int target) {
	int lo = 0, hi = v.size() - 1, mid = 0;
	while (hi - lo > 1) {
		mid = lo + (hi - lo) / 2;
		if (v[mid] < target)
			lo = mid;
		else
			hi = mid;
	}
	std::cout << " target = " << target << '\t' << "LSBS: lo = " << lo << '\t' << "mid = " << mid << '\t' << "hi = " << hi << '\n';

	//return l;
	/*
	if (v[lo] == target) {
		return lo;
		std::cout << "=============================================" << endl;
	}
	else return hi;
	*/
}

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

	if (nums[r] == target) return r;
	if (nums[l] == target) return l;

	return -1;
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

// Template #2 is an advanced form of Binary Search. It is used to search for an element or condition which requires accessing the current index 
// and its immediate right neighbor's index in the array.
// Using half - open interval [left, right)
int binarySearch_2(std::vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size();
	while (left < right) {
		// Prevent (left + right) overflow
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) { return mid; }
		else if (nums[mid] < target) { left = mid + 1; }
		else { right = mid; }
	}

	// Post-processing:
	// End Condition: left == right
	if (left != nums.size() && nums[left] == target) return left;
	return -1;
}

// Template #3 is another unique form of Binary Search.It is used to search for an element or condition which requires accessing the current index 
// and its immediate left and right neighbor's index in the array.
// Using closed interval[left, right]
int binarySearch_3(std::vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size() - 1;
	while (left + 1 < right) {
		// Prevent (left + right) overflow
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	// Post-processing:
	// End Condition: left + 1 == right
	if (nums[left] == target) return left;
	if (nums[right] == target) return right;
	return -1;
}