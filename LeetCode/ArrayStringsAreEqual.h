#pragma once

#include<vector>
#include<string>

// Given two string arrays word1and word2, return true if the two arrays represent the same string, and false otherwise.
// A string is represented by an array if the array elements concatenated in order forms the string.

bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
    std::string s1, s2;
    for (int i = 0; i < word1.size(); i++) {
        s1 += word1[i];
    }
    for (int i = 0; i < word2.size(); i++) {
        s2 += word2[i];
    }
    return s1 == s2;
}