/*
📌 Problem 6: Number of Good Pairs

Problem Statement:

Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if:

nums[i] == nums[j]
i < j

Understanding

We’re basically counting pairs of equal numbers.
Example:
nums = [1,2,3,1,1,3]
Pairs are:
(0,3), (0,4) → both are 1
(3,4) → both are 1
(2,5) → both are 3
Total = 4 pairs.

Approches:

1. Brute Force (Nested Loops)

For each element, check every element after it.
Count pairs.
Time: O(n²)
Works since n <= 100.

2. Optimized (Hashmap / Frequency Counting)

Count how many times each number appears.
If a number appears freq times → number of pairs =2
( freq )=  freq ⋅ (freq−1) / 2
Add these for all numbers.
Time: O(n)	​

*/

#include <iostream>
#include <vector>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << numIdenticalPairs(nums) << endl; // Output: 4
    return 0;
}

