#pragma once

#include<vector>

// given an m x n binary matrix mat of 1's (representing soldiers) and 0's(representing civilians).The soldiers are positioned in front of 
// the civilians.That is, all the 1's will appear to the left of all the 0's in each row.
// A row i is weaker than a row j if one of the following is true:
// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiersand i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

// Solution - Binary Search + Brute Force. Faster than 76%, less than 12%.

std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
	std::vector<int> res_, res;
	int size = mat[0].size();

	//Binary Search: for each row find quantity of soldiers
	for (auto el : mat) {
		int lo = 0, mid = 0, hi = size - 1, pos = size;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (el[mid] == 0) {
				hi = mid - 1;
				pos = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		// the position of the most left civilian (0) equal to quantity of soldiers (1) in the current row
		res_.push_back(pos);
	}

	 
	// Brute Force: the quantity of soldiers in each row: 0 <= qty <= 100
	int counter = 0;
	for (int qty = 0; qty <= 100; qty++) {
		for (int i = 0; i < res_.size(); i++) {
			if (res_[i] == qty) {
				res.push_back(i);
				counter++;
			}
			if (counter == k)
				break;
		}
		if (counter == k)
			break;
	}

	return res;
}
