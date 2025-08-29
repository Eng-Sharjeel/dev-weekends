/*
📌 Problem 4: FizzBuzz

******** Problem Statement ********

Given an integer n, return a string array answer (1-indexed) where:

- answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
- answer[i] == "Fizz" if i is divisible by 3.
- answer[i] == "Buzz" if i is divisible by 5.
- answer[i] == i (as a string) if none of the above conditions are true.

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

******** Approach ***********

Initialize empty vector answer.
Loop i from 1 to n.
Check conditions in order:
divisible by 3 and 5 → "FizzBuzz"
divisible by 3 → "Fizz"
divisible by 5 → "Buzz"
else → to_string(i)
Append result to answer.
Return answer.

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        
        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            }
            else if(i % 3 == 0) {
                answer.push_back("Fizz");
            }
            else if(i % 5 == 0) {
                answer.push_back("Buzz");
            }
            else {
                answer.push_back(to_string(i));
            }
        }
        
        return answer;
    }
};

int main() {
    Solution sol;
    
    int n1 = 3;
    vector<string> res1 = sol.fizzBuzz(n1);
    for(string s : res1) cout << s << " "; 
    cout << endl;

    int n2 = 5;
    vector<string> res2 = sol.fizzBuzz(n2);
    for(string s : res2) cout << s << " "; 
    cout << endl;

    int n3 = 15;
    vector<string> res3 = sol.fizzBuzz(n3);
    for(string s : res3) cout << s << " "; 
 
    cout << endl;

    return 0;
}
