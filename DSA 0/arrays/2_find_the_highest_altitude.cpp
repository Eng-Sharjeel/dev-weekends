/*
📌 Problem 2: Find the Highest Altitude

******* Problem Statement *******
We are given an integer array gain of length n, where each element represents the net gain (positive or negative) in altitude between two consecutive points.
The biker starts at altitude 0.
We need to compute the maximum altitude reached at any point during the trip.

******* Approach *******
netGain = netGain(0 jo ka starting point h) + gain[i] (points jo given h)
and if highest < netGain then:
highest = netGain


******* Dry Run Example *******

Input: gain = [-5, 1, 5, 0,-7]
Start: current = 0, highest = 0
Step 1: current = -5 → highest = 0
Step 2: current = -4 → highest = 0
Step 3: current = 1 → highest = 1
Step 4: current = 1 → highest = 1
Step 5: current = -6 → highest = 1

✅ Output = 1

*/

// solution 1:
#include<iostream>
#include<vector>
using namespace std;


int largestAltitude(vector<int>& gain) {
    int netGain = 0;
    int highest = 0;
    for (int i = 0; i < gain.size(); i++) {
        netGain = netGain + gain[i];   // update running altitude
        gain[i] = netGain;             // store altitude back into gain
        if (highest < netGain) {
            highest = netGain;         // update highest if needed
        }
    }
    return highest;
}

// solution 2 - more cleaner'

int largestAltitude(vector<int>& gain) {
    int netGain = 0, highest = 0;
    for (int g : gain) {
        netGain += g;
        highest = max(highest, netGain);
    }
    return highest;
}


