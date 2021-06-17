#pragma once
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

#include <vector>
#include <string>

void brackets(std::string output, int open, int close, int pairs, std::vector<std::string>& res) {
    if (open == pairs && close == pairs)
        res.push_back(output);
    else {
        if (open < pairs)
            brackets(output + "(", open + 1, close, pairs, res);
        if (close < open)
            brackets(output + ")", open, close + 1, pairs, res);
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    std::string output = "";
    int open = 0;
    int close = 0;
    brackets(output, open, close, n, res);
  	return res;
}