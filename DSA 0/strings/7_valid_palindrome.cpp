/*
📌 Problem: Valid Palindrome

******** Problem Statement ********
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, it reads the same forward and backward. 

Examples:
1. Input: "A man, a plan, a canal: Panama"
   Output: true   → "amanaplanacanalpanama" is a palindrome.

2. Input: "race a car"
   Output: false  → "raceacar" is not a palindrome.

3. Input: " "
   Output: true   → "" (empty after cleaning) is a palindrome.

******** Constraints ********
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.

******** Understanding ********
We need to ignore spaces, punctuation, and case differences.
Only alphanumeric characters (a-z, A-Z, 0-9) matter.
Palindrome means → same string forward and backward.

Example:
"A man, a plan, a canal: Panama"
→ remove non-alphanumeric → "amanaplanacanalpanama"
→ reverse is same → true

******** Approach ********
We can solve using a two-pointer technique:

1. Initialize two pointers:
   - left = 0 (start of string)
   - right = n-1 (end of string)

2. While left < right:
   - If s[left] is not alphanumeric → move left++
   - If s[right] is not alphanumeric → move right--
   - Otherwise:
       - Compare lowercase(s[left]) and lowercase(s[right])
       - If not equal → return false
       - Else move inward: left++, right--

3. If loop finishes → string is palindrome → return true.

******** Complexity ********
Time: O(n)  (each character checked once)
Space: O(1) (constant extra space)
*/

#include <iostream>
#include <cctype>   // for isalnum(), tolower()
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else {
                // Compare after converting to lowercase
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << "Input: \"" << s1 << "\" → Output: " 
         << (sol.isPalindrome(s1) ? "true" : "false") << endl;

    cout << "Input: \"" << s2 << "\" → Output: " 
         << (sol.isPalindrome(s2) ? "true" : "false") << endl;

    cout << "Input: \"" << s3 << "\" → Output: " 
         << (sol.isPalindrome(s3) ? "true" : "false") << endl;

    return 0;
}
