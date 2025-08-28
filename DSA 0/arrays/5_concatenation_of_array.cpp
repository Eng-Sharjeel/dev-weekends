/*
📌 Problem 5: Concatenation of Array

Problem Statement:

Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]

Approach 1:
1. Iterate over an array
2. At each iteration:
    push_back()
3. Return same array

Time complexity: O(n)
Space complexity: O(1) 

Approach 2:

1. Create new array of size 2n, res
2. iterate over the array.
3. At each iteration:
    insert the value arr[i] at i of res array
    insert the value arr[i] at i + 1

*/

// solutions 1: 

#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    vector<int> getConcatenation(vector <int>& nums) {
        int size = nums.size();
        for (int i =0; i < size; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

// solution 2:
class Solution2 {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];      // first half
            ans[i + n] = nums[i];  // second half
        }
        
        return ans;
    }
};

int main() {
    Solution2 obj;
    vector<int> nums = {1, 2, 1};
    vector<int> result = obj.getConcatenation(nums);

    cout << "[ ";
    for (int x : result) cout << x << " ";
    cout << "]" << endl;

    return 0;
}
