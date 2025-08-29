/*
📌 Problem 2: Reverse String

******** Problem Statement ********

Write a function that reverses a string.
The input string is given as an array of characters s.

You must modify the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

********* Understanding ********

We must reverse the array of characters in place → meaning:
No new array allowed.
Only swap elements until reversed.
Use two pointers (left and right).

********* Approach *********

``` Use two pointers Approach ```

Start pointer left = 0, end pointer right = s.size()-1.
While left < right:
Swap s[left] and s[right].
Increment left, decrement right.
Stop when both meet/cross.

👉 Time: O(n)
👉 Space: O(1)

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;

    vector<char> s1 = {'h','e','l','l','o'};
    sol.reverseString(s1);
    for(char c : s1) cout << c;  // Output: olleh
    cout << endl;

    vector<char> s2 = {'H','a','n','n','a','h'};
    sol.reverseString(s2);
    for(char c : s2) cout << c;  // Output: hannaH
    cout << endl;

    return 0;
}
