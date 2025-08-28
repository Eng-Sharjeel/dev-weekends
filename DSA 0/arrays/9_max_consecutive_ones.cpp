/*
📌 Problem: Maximum Consecutive Ones

******* Problem Statement *******
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3

Example 2:
Input: [1,0,1,1,0,1]
Output: 2


******* Understanding *******
- Count the longest sequence of consecutive 1's in the array.
- Example: [1,1,0,1,1,1] → sequences: [1,1] and [1,1,1] → max = 3
- Must be efficient for large arrays.

******* Approach (Two-Pointers / Sliding Window) *******
1. Use a variable `current` to track the current consecutive 1's count.
2. Use a variable `maxCount` to track the maximum found so far.
3. Traverse the array:
   - If nums[i] == 1 → current++
   - Else → current = 0, { jab next element 1 nahi mile ga tu current zero ho jay ga}
   - Update maxCount = max(maxCount, current)
4. Return maxCount

- Time Complexity: O(n)
- Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class MaxConsecutiveOnes {
public:
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        int current = 0;   // current consecutive 1's
        int maxCount = 0;  // maximum consecutive 1's

        for (int num : nums) {
            if (num == 1) {
                current++;
                maxCount = max(maxCount, current);
            } else {
                current = 0; // reset current streak when 0 is found
            }
        }

        return maxCount;
    }
};

int main() {
    MaxConsecutiveOnes solver;

    vector<int> nums1 = {1,1,0,1,1,1};
    vector<int> nums2 = {1,0,1,1,0,1};

    cout << solver.findMaxConsecutiveOnes(nums1) << endl; // 3
    cout << solver.findMaxConsecutiveOnes(nums2) << endl; // 2

    return 0;
}