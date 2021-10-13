#pragma once

// Alice and Bob have a different total number of candies.You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i] 
// is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.
// Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy.
// The total amount of candy a person has is the sum of the number of candies in each box they have.
// Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the 
// number of candies in the box that Bob must exchange.If there are multiple answers, you may return any one of them. It is guaranteed that at 
// least one answer exists.

#include<algorithm>
#include<vector>

std::vector<int> binarySearch(std::vector<int>& less, std::vector<int>& more, int dif) {
	std::vector<int> ans(2);
	int n = more.size();
	for (int el : less) {
		int lo = 0, mid = 0, hi = n - 1;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (more[mid] == el + dif) {
				ans[0] = el;
				ans[1] = more[mid];
				break;
			}
			if (more[mid] < el + dif)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		if (ans[0]) break;
	}
	return ans;
}

std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
	int alice_total = 0, bob_total = 0;
	for (int el : aliceSizes)
		alice_total += el;
	for (int el : bobSizes)
		bob_total += el;
	if (alice_total < bob_total) {
		int dif = (bob_total - alice_total) / 2;
		std::sort(bobSizes.begin(), bobSizes.end());
		return binarySearch(aliceSizes, bobSizes, dif);
	}
	else {
		int dif = (alice_total - bob_total) / 2;
		std::sort(aliceSizes.begin(), aliceSizes.end());
		std::vector<int> ans;
		ans = binarySearch(bobSizes, aliceSizes, dif);
		int alice = ans[1];
		int bob = ans[0];
		ans[0] = alice;
		ans[1] = bob;
		return ans;
	}
}