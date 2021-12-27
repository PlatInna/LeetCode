#pragma once

#include<vector>
#include<string>

// You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item.You are also given a rule  represented by two strings, ruleKeyand ruleValue.
// 
// The ith item is said to match the rule if one of the following is true:
// 
// ruleKey == "type" and ruleValue == typei.
// ruleKey == "color" and ruleValue == colori.
// ruleKey == "name" and ruleValue == namei.
// Return the number of items that match the given rule.

int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue) {
    int count = 0;
    for (auto it : items) {
        if (it[0] == ruleValue and ruleKey == "type" or
            it[1] == ruleValue and ruleKey == "color" or
            it[2] == ruleValue and ruleKey == "name")
            count++;
    }
    return count;
}

int countMatches_(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue) {
    int i = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    int count = 0;
    for (auto it : items) {
        if (it[i] == ruleValue)
            count++;
    }
    return count;
}