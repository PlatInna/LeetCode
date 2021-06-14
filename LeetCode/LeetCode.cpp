// LeetCode.cpp 
//

#include <iostream>
#include <vector>
//#include "minRefuelStops.h"
//#include "palindromePairs.h"
//#include "isSumEqual.h"
#include "maximumUnits.h"
#include "profile.h"

using namespace std;

int main() {
    LOG_DURATION("Total duration");
    vector<vector<int>> boxTypes = { {1, 1} ,{2, 4},{3, 2} };
    int truckSize = 4;

    auto res = maximumUnits(boxTypes, truckSize);

    return 0;
}