// LeetCode.cpp 
//

#include <iostream>
#include <vector>
//#include "minRefuelStops.h"
//#include "palindromePairs.h"
//#include "isSumEqual.h"
//#include "maximumUnits.h"
#include "generateParenthesis.h"
#include "profile.h"

using namespace std;

int main() {
    LOG_DURATION("Total duration");
    int n = 6;
    auto res = generateParenthesis(n);
    for (auto el : res) {
        cout << el << endl;
    }
    return 0;
}