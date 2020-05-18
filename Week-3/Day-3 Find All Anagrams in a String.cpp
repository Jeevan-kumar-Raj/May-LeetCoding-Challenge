Day-3 Find All Anagrams in a String.cpp

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.empty() || s.empty()) {
            return result;
        }

        vector<int> cnts(26);
        for (const auto& c : p) {
            ++cnts[c - 'a'];
        }
        
        for (int left = 0, right = 0; right < s.length(); ++right) {
            --cnts[s[right] - 'a'];
            while (left <= right && cnts[s[right] - 'a'] < 0) {
                ++cnts[s[left++] - 'a'];
            }
            if (right - left + 1 == p.length()) {
                result.emplace_back(left);
            }
        }
        return result;
    }
};
