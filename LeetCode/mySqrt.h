#pragma once

int mySqrt(int x) {
	int r = x;
	int l = 1, m = 0, upper_bound = 0;  
	if (x == 0) return 0;

	while ((r - l) >= 0) {
		m = l + (r - l) / 2; 
		if (m <= x / m) {
			l = m + 1;
			upper_bound = m;
		}
		else r = m - 1;
	}
	return upper_bound;
}
