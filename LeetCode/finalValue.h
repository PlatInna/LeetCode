#pragma once
#include<string>
#include<vector>

// There is a programming language with only four operationsand one variable X :
// ++Xand X++ increments the value of the variable X by 1.
// --X and X-- decrements the value of the variable X by 1.
// Initially, the value of X is 0.
// Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

int finalValueAfterOperations(std::vector<std::string>& operations) {
    int X = 0;
    for (auto el : operations) {
        if (el.find("++") != std::string::npos)
            X++;
        else
            X--;
    }
    return X;
}