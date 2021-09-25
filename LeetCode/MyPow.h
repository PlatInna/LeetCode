#pragma once

// Refactored
double myPow(double x, int n) {
	double res = 1;

	while (n) {
		if (n % 2) n > 0 ? res *= x : res /= x;
		x *= x;
		n /= 2;
	}

	return res;
}

double myPow_(double x, int n) {
	double res = 1;
	if (n == 0) return res;
	if (n > 0) {
		while (n) {
			if (n % 2) res *= x;
			x *= x;
			n /=2;
		}
	}
	else {
		x = 1 / x;
		while (n) {
			if (n % 2) res *= x;
			x *= x;
			n /= 2;
		}
	}

	return res;
}

// Recursion
double myPow__(double x, int n, double res = 1) {
	return n ? myPow__(x * x, n / 2, n % 2 ? (n > 0 ? res * x : res / x) : res) : res;
}

// TLE
double myPow___(double x, int n) {
	double res = 1;
	if (n == 0) return res;
	if (n > 0) {
		while (n) {
			res *= x;
			--n;
		}
	}
	else {
		x = 1 / x;
		while (n) {
			res *= x;
			++n;
		}
	}
	
	return res;
}



