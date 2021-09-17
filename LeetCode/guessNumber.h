#pragma once

int guess(int num) {
	if (num < 100) return  1;
	if (num > 100 ) return -1;
	else return 0;
}

int guessNumber(int n) {
    int l = 1, r = n, m = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (guess(m) < 0) r = m - 1;
        else if (guess(m) > 0) l = m + 1;
        else return m;
    }
    return m;
}