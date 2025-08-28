/*
📌 Problem 7: Shuffle the array

******* Problem Statement *******

You are given an array nums of size 2n structured as [x1, x2, ..., xn, y1, y2, ..., yn].
Return it rearranged as [x1, y1, x2, y2, ..., xn, yn].

******* Understanding *******

Array has exactly 2n elements.
First half = x values
Second half = y values.
We need to merge them alternately.

Example:
Input: [2,5,1,3,4,7], n=3
First half: [2,5,1]
Second half: [3,4,7]
Output: [2,3,5,4,1,7]

******* Approach *******

2n size ki array h, means array ka 8 elements h tu n = 4 hoga, 
phir hum resultant array me values push kre ga in a way:

i aur (i + n), in elements ko pick kre ga or resultant me push kr de ga

*/

#include <iostream>
#include <vector>
using namespace std;

class ShuffleArray {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        result.reserve(2 * n); // reserve space for efficiency

        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);     // x[i]
            result.push_back(nums[i + n]); // y[i]
        }

        return result;
    }
};

int main() {
    ShuffleArray obj;

    vector<int> nums1 = {2,5,1,3,4,7};
    vector<int> nums2 = {1,2,3,4,4,3,2,1};
    vector<int> nums3 = {1,1,2,2};

    vector<int> res1 = obj.shuffle(nums1, 3);
    vector<int> res2 = obj.shuffle(nums2, 4);
    vector<int> res3 = obj.shuffle(nums3, 2);

    for (int x : res1) cout << x << " "; cout << endl; // 2 3 5 4 1 7
    for (int x : res2) cout << x << " "; cout << endl; // 1 4 2 3 3 2 4 1
    for (int x : res3) cout << x << " "; cout << endl; // 1 2 1 2

    return 0;
}

