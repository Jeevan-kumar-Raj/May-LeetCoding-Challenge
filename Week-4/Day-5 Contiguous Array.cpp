Day-5 Contiguous Array.cpp

/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, count = 0;
        unordered_map<int, int> lookup;
        lookup[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 1 ? 1 : -1;
            if (lookup.count(count)) {
                result = max(result, i - lookup[count]);
            } else {
                lookup[count] = i;
            }
        }
        return result;
    }
};