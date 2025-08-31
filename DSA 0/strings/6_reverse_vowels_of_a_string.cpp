/*
📌 Problem 6: Reverse Vowels of a String

Given a string s, reverse only the vowels in the string and return it.
Vowels: a, e, i, o, u (both lowercase and uppercase).

Constraints:

1 <= s.length <= 3 * 10^5
s consists of printable ASCII characters.

******** Understanding *********

We only care about vowels (a, e, i, o, u, A, E, I, O, U).
Need to reverse vowels in-place while keeping consonants at the same position.
Example:
"IceCreAm" → vowels = I, e, e, A → reverse them = A, e, e, I
New string = "AceCreIm".

******** Approach *********

```Use Two Pointers ```

left at start, right at end.
Move inward until left < right.
If s[left] is not vowel → move left++.
If s[right] is not vowel → move right--.
If both are vowels → swap them, then move left++, right--.
Continue until all vowels are reversed.

✅ Time Complexity: O(n)
✅ Space Complexity: O(1) (in-place).

*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u' ||
               ch =='A' || ch =='E' || ch =='I' || ch =='O' || ch =='U';
    }
    
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (!isVowel(s[left])) {
                left++;
            } 
            else if (!isVowel(s[right])) {
                right--;
            } 
            else {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    string s1 = "IceCreAm";
    string s2 = "leetcode";
    
    cout << "Input: " << s1 << " → Output: " << sol.reverseVowels(s1) << endl;
    cout << "Input: " << s2 << " → Output: " << sol.reverseVowels(s2) << endl;
    
    return 0;
}
