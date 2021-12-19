#pragma once

//There are n kids with candies.You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
//Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
//Note that multiple kids can have the greatest number of candies.

#include<vector>
#include<algorithm>

std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
    int max = candies[0];
    for (int i = 1; i < candies.size(); i++)
        if (candies[i] > max)
            max = candies[i];
    std::vector<bool> result;
    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] + extraCandies < max) {
            result.push_back(false);
            
        }
        else {
            result.push_back(true);
        }
    }
    return result;
}

std::vector<bool> kidsWithCandies_(std::vector<int>& candies, int extraCandies) {
    std::vector<bool> res;
    auto max = *(std::max_element(candies.begin(), candies.end()));
    for (int i = 0; i < candies.size(); i++) {
            (candies[i] + extraCandies) < max ? res.push_back(0) : res.push_back(1);
    }
    return res;
}