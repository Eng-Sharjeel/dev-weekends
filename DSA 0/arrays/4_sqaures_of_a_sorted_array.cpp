/*
📌 Problem 4: Squares of a Sorted Array

2. Problem Statement

You are given a sorted integer array nums.
Return a new array containing the squares of each number, also sorted in non-decreasing order.
nums can have negative numbers.

Approach 1:

Square every element → O(n)
Sort the resulting array → O(n log n)

-> Time Complexity: O(n log n)
-> Space Complexity: O(n)

Approach 2: for optimized approach
***** Use two pointers *****
one at start (left) and one at end (right) --> can be i or j

-> Time Complexity: O(n)
-> Space Complexity: O(n)

*/

// solution 1:

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {

    for (auto i = 0; i<nums.size(); i++){
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    
    return nums;

}

// solutions 2: optimized

#include <cmath>
using namespace std;

vector<int> sortedSquares_optimized(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int pos = n - 1;
    
    // abs means absolute value of x --> abs(-4) = 4

    while(left <= right) {
        if(abs(nums[left]) > abs(nums[right])) {
            result[pos] = nums[left] * nums[left];
            left++;
        } else {
            result[pos] = nums[right] * nums[right];
            right--;
        }
        pos--;
    }
    return result;
}
//          0   1  2  3   4
// nums = [-4, -1, 0, 3, 10]
/*
    ***** DRY RUN *****
Initial:
left=0 (-4), right=4 (10), pos=4, result=[0,0,0,0,0]

abs(-4)=4 > abs(10)=10 → false
else → 10^2=100 → result[4]
→ right=3, pos=3
result = [0,0,0,0,100]

abs(-4)=4 > abs(3)=3 → true
if → (-4)^2=16 → result[3]
→ left=1, pos=2
result = [0,0,0,16,100]

abs(-1)=1 > abs(3)=3 → false
else → 3^2=9 → result[2]
→ right=2, pos=1
result = [0,0,9,16,100]

abs(-1)=1 > abs(0)=0 → true
if → (-1)^2=1 → result[1]
→ left=2, pos=0
result = [0,1,9,16,100]

abs(0)=0 > abs(0)=0 → false
else → 0^2=0 → result[0]
→ right=1, pos=-1
result = [0,1,9,16,100]


*/