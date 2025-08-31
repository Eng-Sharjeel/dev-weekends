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
"listen" and "silent" → same letters & same frequencies → return false.
simlarly, "cat"  and "car" -> different letters & frequencies -> false
********* Approach *********

// Step 1: If lengths are not same, can't be anagrams
// Step 2: Sort both strings
// Step 3: Compare

*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: If lengths are not same, can't be anagrams
        if(s.size() != t.size()) return false;

        // Step 2: Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Step 3: Compare
        return s == t;
    }
};

// optimized appraoch solution
class Solution {
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
