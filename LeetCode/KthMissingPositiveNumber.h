#pragma once

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Find the kth positive integer that is missing from this array.

#include<algorithm>
#include<vector>
#include <iostream>

int findKthPositive(std::vector<int>& arr, int k) {
	int n = arr.size();
	int last_el = arr.back();
	// corner cases 
	if (last_el == n)
		return last_el + k;

	// Binary Search, tricky, it was hard for me to guess that i <= 2000 !!!! :)
	int counter = 0, res = -1, i = 1; 
	for (; i <= 2000; i++) {
		int lo = 0, mid = 0, hi = n - 1;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (arr[mid] == i)
				break;
			if (arr[mid] < i) {
				lo = mid+1;
			}
			else {
				hi = mid-1;
			}
		}
		if (arr[mid] == i)
			;
		else {
			counter++;
		}
		if (counter == k) {
			res = i;
			break;
		}
	}
	return res;
}
