#pragma once

// You are a product managerand currently leading a team to develop a new product.Unfortunately, the latest version of your product fails the 
// quality check.Since each version is developed based on the previous version, all the versions after a bad version are also bad.
// Suppose you have n versions[1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
// You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version.
// You should minimize the number of calls to the API.

bool isBadVersion(int version, int bad) {
	int bad_version = bad;
	if (version >= bad_version) 
		return  true;
	else
		return false;
}

int firstBadVersion(int n, int bad) {
	if (n == 1)
		return 1;

	int l = 1, r = n;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (isBadVersion(m, bad) and !isBadVersion(m + 1, bad)) { return m; }
		else if (!isBadVersion(m, bad)) { l = m + 1; }
		else { r = m; }
	}

	if (l != r && isBadVersion(l, bad)) return l;
	else return r;
}

int firstBadVersion_(int n) {
	int l = 1, r = n, m = 0, bad = n ;
	while (l < r) {
		m = l + (r - l) / 2;
		if (!isBadVersion(m, bad)) l = m + 1;   /* Only one call to API */
		else r = m;
	}
	return l;   /* Because there will alway be a bad version, return lower here */
}