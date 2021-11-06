#pragma once

#include<iostream>

void triangularMatrices(int rows, int cols) {
	if (rows > 9 || cols > 9 || rows != cols) {
		std::cout << "rows and cols should be less 10 and uqual each other" << '\n';
		return;
	}

	int** tm = new int* [rows];
	//auto tm = new int* [rows];
	for (int r = 0; r < rows; r++) {
		tm[r] = new int[r + 1];
		for (int c = 0; c < r + 1; c++) {
			tm[r][c] = (r + 1) * 10 + c + 1;
		}
	}
	// print triangular matrices
	std::cout << "===== print triangular matrices =====" << '\n';
	for (int r = 0; r < rows; r++) {
		std::cout << '\t';
		for (int c = 0; c < r + 1; c++) {
			std::cout << tm[r][c] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	// free memory
	for (int r = 0; r < rows; r++) {
		delete[] tm[r];
	}
	delete[] tm;
}