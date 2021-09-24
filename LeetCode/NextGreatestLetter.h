#pragma once

// Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that 
// is larger than target.
// Note that the letters wrap around.
// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.

char nextGreatestLetter(vector<char>& letters, char target) {
	int l = 0, r = letters.size() - 1, pos = 0, m = 0;

	// extreme cases
	if (target < letters[0] or target > letters[r] or target == letters[r])
		return letters[0];

	if (r == 1) {
		if (target == letters[0]) return letters[1];
		else if(target > letters[0] and target < letters[1]) return letters[1];
		else return letters[0];
	}

	// if target exists l == target max positon (right position) otherwise r == position of the next greatest letter 
	while (r - l > 1) {
		m = l + (r - l) / 2;
		if (letters[m] <= target) l = m;
		else r = m;
	}

	if (letters[l] == target) {
		if (l != letters.size() - 1) pos = l + 1;
	}
	else {
		pos = r;
	}

	return letters[pos];
}