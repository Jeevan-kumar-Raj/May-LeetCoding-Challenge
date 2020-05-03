Day-2 Jewels and Stones.cpp

/*

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
   Hide Hint #1  
For each stone, check if it is a jewel.

*/

// Time:  O(m + n)
// Space: O(n)

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> lookup;
        for (const auto& j : J) {
            lookup.emplace(j);
        }
        int result = 0;
        for (const auto& s : S) {
            result += lookup.count(s);
        }
        return result;
    }
};
