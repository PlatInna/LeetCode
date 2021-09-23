#pragma once

#include <cstdlib>
#include <vector>

std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {

	int l = 0, r = arr.size() - 1, m = 0, a, b;
	std::vector<int> res;

	if (arr.size() == 1 or k == r + 1) return arr;

	if (x < arr[0]) {
		arr.resize(k);
		return arr;
	}

	if (x > arr[r]) {
		for (int i = r + 1 - k; i <= r; i++) {
			res.push_back(arr[i]);
		}
		return res;
	}

	if (r - k == 0) {
		if (std::abs(x - arr[0]) <= std::abs(x - arr[r])) {
			arr.resize(k);
			return arr;
		}
		else {
			for (int i = 1; i <= r; i++) {
				res.push_back(arr[i]);
			}
			return res;
		}
	}

	// find x position or left and right positions if multiple x
	// a is left position if multiple x
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (arr[m] < x) l = m;
		else r = m;
	}
	// important to check r first!!!
	if (arr[r] == x) a = r;
	else a = l;

	// b is right position for multiple x
	l = 0, r = arr.size() - 1, m = 0;
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (arr[m] <= x) l = m;
		else r = m;
	}
	// important to check l first!!!
	if (arr[l] == x) b = l;
	else b = r;

	// find closest elements
	// if x exist in arr
	if (arr[a] == x) { 
		for (int i = b + 1 - a; i < k; i++) {
			if (a == 0) b++;
			else if (b == arr.size() - 1) a--;
			else if (std::abs(x - arr[a - 1]) <= std::abs(arr[b + 1] - x)) a--;
			else b++;
		}
	}
	// if x does not exist in arr
	else {
		for (int i = 1; i < k; i++) {
			if (a == 0) b++;
			else if (b == arr.size() - 1) a--;
			else if (std::abs(x - arr[a - 1]) <= std::abs(arr[b + 1] - x)) a--;
			else b++;
		}
		if (std::abs(x - arr[a]) <= std::abs(x - arr[b])) b--;
		else a++;
	}

	for (int i = a; i <= b; i++) {
		res.push_back(arr[i]);
	}

	return res;
}