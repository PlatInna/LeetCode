#pragma once

//You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank.Return the wealth that the richest customer has.
//A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

#include<vector>

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int the_richest_wealth = 0;
    int wealth = 0;
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 0; j < accounts[i].size(); j++) {
            wealth += accounts[i][j];
        }
        if (wealth > the_richest_wealth) {
            the_richest_wealth = wealth;
        }
        wealth = 0;
    }
    return the_richest_wealth;
}