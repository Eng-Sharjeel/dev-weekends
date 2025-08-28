/*
📌 Problem 1: Running Sum of Array

******** Problem Statement *******
We are given an array nums.
We need to return another array runningSum where each element is the sum of all elements from index 0 to i.

******* Example *******
Input: [1,2,3,4]
Output: [1,3,6,10] Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

nums[i] = nums[i] + nums[i-1]

*/

// pseudo code - Logic

#include <vector>
#include <iostream>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i] + nums[i-1];
    }
    return nums;
}



