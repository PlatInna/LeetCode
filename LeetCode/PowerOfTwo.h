#pragma once

// Given an integer n, return true if it is a power of two.Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2^x.

bool isPowerOfTwo(int n) { // TL
	if (n == 1)
		return true;
	if (n % 2 != 0)
		return false;
	return isPowerOfTwo(n >>= 1);
}