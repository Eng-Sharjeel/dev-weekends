/*

📌 Problem 4: Merge Strings Alternately (Using While Loop)

******** Problem Statement ********

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"

********* Understanding ********

We merge two strings character by character alternately.
- Start with word1[0], then word2[0], and so on.
- If one string is longer, append remaining characters at the end.

********* Approach **********

Two pointer technique → handle both strings simultaneously.
Separate loops → cleanly handle the case when strings are of unequal lengths.

*/

#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string res = "";
        while(i < word1.size() && j < word2.size()) {
            res += word1[i++];
            res += word2[j++];
        }
        // append 
        while(i < word1.size()) res += word1[i++];
        while(j < word2.size()) res += word2[j++];

        return res;
    }
};

int main() {
    Solution sol;

    string w1 = "AbC", w2 = "pQr";
    cout << sol.mergeAlternately(w1, w2) << endl; // Output: ApbCQr

    string w3 = "aB", w4 = "PQrs";
    cout << sol.mergeAlternately(w3, w4) << endl; // Output: aPBQrs

    string w5 = "ABcd", w6 = "pq";
    cout << sol.mergeAlternately(w5, w6) << endl; // Output: ApBqcd

    return 0;
}