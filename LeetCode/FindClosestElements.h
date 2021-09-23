#pragma once

#include <cstdlib>
#include <vector>

std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
	int l = 0, r = arr.size() - 1, m = 0, a, b;
	std::vector<int> res;
	if (arr.size() == 1) return arr;

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

	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (arr[m] < x) l = m;
		else r = m;
	}

	if (arr[r] == x) a = r;
	else a = l;

	l = 0, r = arr.size() - 1, m = 0;
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (arr[m] <= x) l = m;
		else r = m;
	}

	if (arr[l] == x) b = l;
	else b = r;

	if (a == b) {
		if(a != 0 and b != arr.size() - 1 and std::abs(arr[a] - arr[a-1]) <= std::abs(arr[b] - arr[b + 1])
	}


	/*
	for (int el : arr) {
		std::cout << el << ' ';
	}
	std::cout << '\n';
	for (int el : res) {
		std::cout << el << ' ';
	}
	std::cout << '\n';
	//std::cout << '[' << res[0] << ',' << res[1] << ']' << '\n';
	*/
	return res;
}