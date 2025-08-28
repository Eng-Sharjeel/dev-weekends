/*
📌 Problem 3: Final Value of variable (X) After Performing Operations

******* Problem Statement *******

We are given an array of operations where each element is one of four possible strings:
"++X" or "X++" → increment X by 1
"--X" or "X--" → decrement X by 1

Initially, X = 0.
We must return the final value of X after performing all operations.

******* Approach *******

Start with X = 0.

For each string in operations:
If it contains "++", increment X.
If it contains "--", decrement X.
Return the final value of X.


*/

// solution 1: pseudo code

#include <iostream>
#include <vector>

using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int X = 0;  // start value

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i] == "++X" || operations[i] == "X++") {
            X++;
        } 
        else if (operations[i] == "--X" || operations[i] == "X--") {
            X--;
        }
    }
    return X;
}


