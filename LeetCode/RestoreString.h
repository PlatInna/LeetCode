#pragma once

#include<vector>
#include<string>

//You are given a string sand an integer array indices of the same length.The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
//Return the shuffled string.

std::string restoreString_(std::string s, std::vector<int>& indices) {
    std::string res = "";
    std::vector<char> c(s.size());
    for (int i = 0; i < s.size(); i++) {
        c[indices[i]] = s[i];
    }
    for (int i = 0; i < c.size(); i++) {
        res.append(1, c[i]);
    }
    return res;
}

std::string restoreString(std::string s, std::vector<int>& indices) {
    std::string res = s;
    for (int i = 0; i < s.size(); i++) {
        res[indices[i]] = s[i];
    }
    return res;
}

std::string restoreString__(std::string s, std::vector<int>& indices) {
    std::string res = s; int j = 0;
    for (auto i : indices) res[i] = s[j++];
    return res;
}