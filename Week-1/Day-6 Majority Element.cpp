Day-6 Majority Element.cpp

/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], cnt = 1;
        for (const auto& i : nums) {
            if (i == ans) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    ans = i;
                    cnt = 1;
                }
            }
        }
        return ans; 
    }
};
