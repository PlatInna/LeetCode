#pragma once

#include<vector>
#include<string>

// You are given a string allowed consisting of distinct charactersand an array of strings words.A string is consistent if all characters in the string  appear in the string allowed.
// Return the number of consistent strings in the array words.

int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
    //int count = 0;
    int count = words.size();
    for (auto w : words) {
        //count++;
        for (int i = 0; i < w.size(); i++) {
            if (allowed.find(w[i]) == std::string::npos) {
                count--;
                break;
            }
        }
    }
    return count;
}