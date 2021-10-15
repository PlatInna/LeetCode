#pragma once

#include <vector>

// Given a m x n matrix grid which is sorted in non - increasing order both row - wise and column - wise, return the number of negative numbers in grid.
// Example 1:
// Input: grid = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
// Output : 8
// Explanation : There are 8 negatives number in the matrix.

int countNegatives(std::vector<std::vector<int>>& grid) {
	int counter = 0, lo = 0, mid = 0;
	int size = grid[0].size(); // to avoid multiple calls of grid.size();
	int hi = size - 1, negativ_pos = size;

	for (auto el : grid) {
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (el[mid] < 0) {
				hi = mid - 1;
				negativ_pos = mid;
			}
			else
				lo = mid + 1;
		}
		counter += size - negativ_pos;
		lo = 0, mid = 0;
		hi = size - 1;
		negativ_pos = size;
	}
	return counter;
}
