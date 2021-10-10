#pragma once

// Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
// The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where | arr1[i] - arr2[j]| <= d.

#include<algorithm>
#include<vector>

int findTheDistanceValue(std::vector<int>&arr1, std::vector<int>& arr2, int d) {
	std::sort(arr2.begin(), arr2.end());
	int counter = arr1.size(), size = arr2.size();
	for (int el : arr1) {
		int lo = 0, mid = 0, hi = size - 1;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (std::abs(el - arr2[mid]) <= d) {
				counter--;
				break;
			}
			if (arr2[mid] < el) 
				lo = mid + 1;
			else
				hi = mid - 1;
		}
	}
	return counter;
}