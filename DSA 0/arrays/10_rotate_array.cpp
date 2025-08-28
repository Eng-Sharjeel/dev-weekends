/*
📌 Problem 10: Rotate Array
Given an integer array nums, rotate the array to the right by k steps.
Rotation means shifting every element right, and the last element wraps around to the front.

Do it in-place if possible.

Problem Understanding:

Example 1:

nums = [1,2,3,4,5,6,7], k = 3

1 step → [7,1,2,3,4,5,6]
2 steps → [6,7,1,2,3,4,5]
3 steps → [5,6,7,1,2,3,4]

Example 2:

nums = [-1,-100,3,99], k = 2

1 step → [99,-1,-100,3]
2 steps → [3,99,-1,-100] 

Approach:
1. Reverse the whole array 
2. Reverse 1st k elements of array 
3. Reverse all elements after k

answer: 5,6,7,1,2,3,4, k=3

1. --> 7,6,5,4,3,2,1
2. --> 5,6,7, 4,3,2,1
3. --> 5,6,7, 1,2,3,4  (matches the answer)

*/

#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // in case k > n

        // Step 1: reverse whole array
        reverse(nums.begin(), nums.end());
        
        // Step 2: reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,2,3,4,5,6,7};
    obj.rotate(nums, 3);

    cout << "[ ";
    for (int x : nums) cout << x << " ";
    cout << "]" << endl;

    return 0;
}
