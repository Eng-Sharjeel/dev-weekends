/*
📌 Problem: Move Zeroes

******* Problem Statement *******

Given an integer array nums, move all 0’s to the end of it while maintaining the relative order of the non-zero elements.
Must do this in-place, without copying the array.

Example:
Input: [0,1,0,3,12] → Output: [1,3,12,0,0]
Input: [0] → Output: [0]

******** Understanding ********

zero elements ko last prr shift krna h or baki elements same order me rhy ga
bss zeros end pr chly jaein ga

******* appraoch 1 ********

2 arrays banay ga aik me zero add kr de ga or 
2nd array me non zero elements in the order add kr de ga
phir dono ko combine kr de ga 
zero wali array ab end prr chly jay gi

ya phir aik count le ga or usme zeros ko count kre ga or new array me non zero elements push kr dega
or jitna zeros ka count hua utny zero end prr ad kr de ga 

but problem is we donot have to copy or make another array , we have to optimized it

******* Optimzed Approach *******

``` use two pointers technique ```

2 pointers le ga
l or r , means left and right 

               l
questions --> [2 , 0 , 3, 1, 5, 0]
               r

jab bhi r non-zero element prr hoga tu swap kre ga
jab bhi swap kre ga l or r me increment +1 ka kre ga
r zero ko indicate kre ga simple, sirf r ko increment kr de ga, l apni position pr hi rhy ga
or isi trah sa pora array ko traverse kre ga

               l
              [2 , 0 , 3, 1, 5, 0]
               r
r on non-zero --> swap : 1st element ko swag kre ga tu udhr hi rhy ga bss l or r me +1 ho jay ga

                   l
              [2 , 0 , 3, 1, 5, 0]
                   r
now, r is on zero , simply r++ and l remains same
                   l
              [2 , 0 , 3, 1, 5, 0]
                       r

r on non-zero, l or r ko swap kr de ga, or dono me +1 increment hon jay ga

                       l
              [2 , 3 , 0, 1, 5, 0]
                          r
                          
same steps follow kre ga till r reach its boundary or out of boundary

*/

#include <iostream>
#include <vector>
using namespace std;

class MoveZeroes {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0; // pointer to place next non-zero

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};

int main() {
    MoveZeroes solver;

    vector<int> nums1 = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0};

    solver.moveZeroes(nums1);
    solver.moveZeroes(nums2);

    // Output results
    for (int x : nums1) cout << x << " "; cout << endl; // 1 3 12 0 0
    for (int x : nums2) cout << x << " "; cout << endl; // 0

    return 0;
}