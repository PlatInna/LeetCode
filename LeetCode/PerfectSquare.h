#pragma once

int mySqrt(int x) {
	int r = x;
	int l = 1, m = 0, upper_bound = 0;

	while (l <= r) {
		m = l + (r - l) / 2;
		if (m <= x / m) {
			l = m + 1;
			upper_bound = m;
		}
		else r = m - 1;
	}
	return upper_bound;
}

bool isPerfectSquare(int num) {
	if (num == 1) return true;
	if (num == 2) return false;
	int sr = mySqrt(num);
	if(sr*sr == num) return true;
	return false;
}