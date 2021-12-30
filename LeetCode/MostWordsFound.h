#pragma once

#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

// A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
// You are given an array of strings sentences, where each sentences[i] represents a single sentence.
// Return the maximum number of words that appear in a single sentence.

int mostWordsFound(std::vector<std::string>& sentences) {
    int max_count = 0;
    for (auto s : sentences) {
        std::string::size_type n = 0;
        int count = 0;
        while (n != std::string::npos) {
            n = s.find(' ', n + 1);
            count++;
        }
        if (count > max_count) {
            max_count = count;
        }
    }
    return max_count;
}

int mostWordsFound_(std::vector<std::string>& s) {
    return 1 + std::accumulate(std::begin(s), std::end(s), 0, [](int res, const auto& s) {
        return std::max(res, (int)std::count(std::begin(s), std::end(s), ' ')); });
}