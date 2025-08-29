/*
📌 Problem 1: Jewels and Stones

******** Problem Statement ********

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

******** Understanding *********

We have two strings:

jewels: contains unique characters → types of jewels.
stones: contains stones we own.
Task: Count how many characters in stones are also present in jewels.

********* Example ********
jewels = "aA", stones = "aAAbbbb" → Output = 3
jewels = "z", stones = "ZZ" → Output = 0

******** Appraoch ********

Option 1: Brute Force

For each character in stones, loop over jewels to check if it exists.
Increment count if found.
Time: O(n*m)

Option 2: Optimized (HashSet) ✅

Store all jewels in a set (quick lookup).
Loop through stones → if stone is in set → increment count.
Time: O(n+m), Space: O(m)
*/


#include <iostream>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end()); 
        int count = 0;
        
        for(char s : stones) {
            if(jewelSet.count(s)) { 
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution1 sol;
    cout << sol.numJewelsInStones("aA", "aAAbbbb") << endl; // Output: 3
    cout << sol.numJewelsInStones("z", "ZZ") << endl;       // Output: 0
    return 0;
}

// approach 2:

class Solution2 {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        int n=jewels.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<stones.size();j++){
                if(jewels[i]==stones[j]){
                    count++;
                }
            }
        } return count;
        
    }
};
