#pragma once
/*
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where 
boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put 
on the truck as long as the number of boxes does not exceed truckSize.
Return the maximum total number of units that can be put on the truck.
*/

#include<vector>
#include<algorithm>

int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
	int res = 0;
	int empty_space = truckSize;
	std::sort(boxTypes.begin(), boxTypes.end(), [](auto a, auto b) { return b[1] < a[1]; });
	for(size_t i = 0; i < boxTypes.size(); i++) {
		if (empty_space > 0) {
			if (empty_space >= boxTypes[i][0]) {
				empty_space -= boxTypes[i][0];
				res += boxTypes[i][0] * boxTypes[i][1];
			}
			else {
				res += empty_space * boxTypes[i][1];
				empty_space = 0;
			}
		}
		else {
			break;
		}
	}
	return res;
}
