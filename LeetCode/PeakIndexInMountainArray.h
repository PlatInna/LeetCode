#pragma once

#include<vector>

int peakIndexInMountainArray(std::vector<int>&arr) {
	int lo = 0, mid = 0, hi = arr.size() - 1;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
			return mid;
		else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}
