#pragma once
/*
Given an integer array nums, handle multiple queries of the following types:
    - Update the value of an element in nums.
    - Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:
    - NumArray(int[] nums) Initializes the object with the integer array nums.
    - void update(int index, int val) Updates the value of nums[index] to be val.
    - int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive 
      (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
Example 1:
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]
Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
*/

#include <vector>
#include <numeric>
#include <algorithm>

class NumArray { // вариант - дерево отрезков в векторе
public:
    NumArray(std::vector<int>& nums) : 
        data(nums),
        N(nums.size() - 1)
    {
        seg_tree.resize((N + 1) * 4);
        buildSegTree(1, 0, N);
    }

    void update(int index, int val) {
        updateSegTree(1, 0, N, index, val);
    }

    int sumRange(int left, int right) {
        return sumRequest(1, 0, N, left, right);
    }

private:
    std::vector<int> data, seg_tree;
    const int N;

    void buildSegTree(int node_idx, int l_bound, int r_bound ) {
        if (l_bound == r_bound) {
            seg_tree[node_idx] = data[l_bound];
        }
        else {
            int middle = (l_bound + r_bound) / 2;
            buildSegTree(node_idx * 2, l_bound, middle);
            buildSegTree(node_idx * 2 + 1, middle + 1, r_bound);
            seg_tree[node_idx] = seg_tree[node_idx * 2] + seg_tree[node_idx * 2 + 1];
        }
    }

    void updateSegTree(int node_idx, int l_bound, int r_bound, int pos, int new_val) {
        if (l_bound == r_bound) {
            seg_tree[node_idx] = new_val;
        }
        else {
            int middle = (l_bound + r_bound) / 2;
            if (pos <= middle) {
                updateSegTree(node_idx * 2, l_bound, middle, pos, new_val);
            }
            else {
                updateSegTree(node_idx * 2 + 1, middle + 1, r_bound, pos, new_val);
            }
            seg_tree[node_idx] = seg_tree[node_idx * 2] + seg_tree[node_idx * 2 + 1];
        }
    }

    int sumRequest(int node_idx, int l_bound, int r_bound, int l, int r) {
        if (l > r)
            return 0;
        if (l == l_bound && r == r_bound)
            return seg_tree[node_idx];
        int middle = (l_bound + r_bound) / 2;
        return sumRequest(node_idx * 2    , l_bound   , middle , l                      , std::min(r, middle))
             + sumRequest(node_idx * 2 + 1, middle + 1, r_bound, std::max(l, middle + 1), r                  );
    }
};