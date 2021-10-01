#pragma once

#include <vector>

// Given a 1 - indexed array of integers numbers that is already sorted in non - decreasing order, find two numbers such that they add up to a 
// specific target number.Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.
// Return the indices of the two numbers, index1and index2, as an integer array[index1, index2] of length 2.

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

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
	std::vector<int> res = { 1,2 };

	// extreme case
	if (numbers.size() == 2) return res;

	// let's define: a + b = target and than let's say:
	int b = target / 2;

	//use left side Binary Search to find b pos
	int b_pos = leftsideBinarySearch(numbers, b);
	if (numbers[b_pos] + numbers[b_pos + 1] == target) {
		res[0] = ++b_pos;
		res[1] = ++b_pos;
		return res;
	}
	else {
		//naive implementation, could be speed up if use ranges
		while (b_pos < numbers.size()) {
			int a = target - numbers[b_pos];
			int a_pos = leftsideBinarySearch(numbers, a);
			if (numbers[a_pos] == a && a_pos != b_pos) {
				res[0] = ++a_pos;
				res[1] = ++b_pos;
				return res;
			}
			else {
				b_pos++;
			}
		}
		// never reach if the tests are generated such that there is exactly one solution.
		return res; 
	}
}