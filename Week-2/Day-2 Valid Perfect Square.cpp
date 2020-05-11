Day-2 Valid Perfect Square.cpp

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

*/

#define li long int
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        li high = 100000;
        li low = 1;
        li mid;
        li sq;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            sq = mid*mid;
            if(sq==num)
                return true;
            else if(sq>num)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};
