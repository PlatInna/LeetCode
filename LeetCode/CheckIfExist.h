#pragma once

#include<vector>
#include<algorithm>


bool checkIfExist(std::vector<int> arr) {
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		int target = arr[i] * 2;
		int low = 0, mid = 0, hi = arr.size() - 1;
		while (low <= hi) {
			mid = low + (hi - low) / 2;
			if (arr[mid] == target && mid != i) return true;
			if (arr[mid] < target)
				low = mid + 1;
			else
				hi = mid - 1;
		}
	}
	return false;
}