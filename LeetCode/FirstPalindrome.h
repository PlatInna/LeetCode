#pragma once

#include<string>
#include<vector>

//Given an array of strings words, return the first palindromic string in the array.If there is no such string, return an empty string "".
//A string is palindromic if it reads the same forwardand backward.

std::string firstPalindrome(std::vector<std::string>& words) {
    for (auto w : words) {
        if (w.size() == 1)
            return w;
        for (int i = 0; i < w.size() / 2; i++) {
            if (w[i] != w[w.size() - 1 - i])
                break;
            if (i == w.size() / 2 - 1)
                return w;
        }
    }
    return "";
}
