/*
📌 Problem 5: Valid Anagram

******** Problem Statement ********
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

******* Follow-up (Unicode Characters) *******
If the strings can contain Unicode characters, we cannot use a fixed-size array.
Use a hash map to count frequencies instead:

********* Understanding *********
Two strings are `anagrams` if they contain the same characters with the same frequencies.
Example: "anagram" and "nagaram" → same letters → return true.
"listen" and "silent" → same letters & same frequencies → true.
"cat" and "car" → different letters → false

********* Approach *********
- Step 1: If lengths are not same, can't be anagrams
- Step 2: Sort both strings
- Step 3: Compare
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Sorting
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Approach 2: Optimized using frequency count
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> freq(26, 0); // For lowercase English letters only

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int count : freq) {
            if(count != 0) return false;
        }
        return true;
    }
};

int main() {
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";

    Solution1 sol1;
    Solution2 sol2;

    cout << "Using Sorting Approach:" << endl;
    cout << s1 << " & " << t1 << " -> " << (sol1.isAnagram(s1, t1) ? "true" : "false") << endl;
    cout << s2 << " & " << t2 << " -> " << (sol1.isAnagram(s2, t2) ? "true" : "false") << endl;

    cout << "\nUsing Frequency Count Approach:" << endl;
    cout << s1 << " & " << t1 << " -> " << (sol2.isAnagram(s1, t1) ? "true" : "false") << endl;
    cout << s2 << " & " << t2 << " -> " << (sol2.isAnagram(s2, t2) ? "true" : "false") << endl;

    return 0;
}
