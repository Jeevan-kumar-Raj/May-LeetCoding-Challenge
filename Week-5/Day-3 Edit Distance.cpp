Day-3 Edit Distance.cpp

/*

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


*/

class Solution {
public:
    int minDistance(string word1, string word2) {
 int a=word1.length(), b=word2.length();
    int min_steps[a+1][b+1];
    for(int i=0; i<= a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0)min_steps[i][j]=j;//all insert operations
            else if(j==0)min_steps[i][j]=i;//all delete operations
            else if(word1[i-1]==word2[j-1]) min_steps[i][j]=min_steps[i-1][j-1];
            else 
            {
                min_steps[i][j] = 1 + min(min_steps[i-1][j-1], min(min_steps[i-1][j], min_steps[i][j-1])) ;              
            }
        }
    }    
    return min_steps[a][b];
    }
};




/// Python sol

# Time:  O(n * m)
# Space: O(n + m)

class Solution(object):
    # @return an integer
    def minDistance(self, word1, word2):
        if len(word1) < len(word2):
            return self.minDistance(word2, word1)

        distance = [i for i in xrange(len(word2) + 1)]

        for i in xrange(1, len(word1) + 1):
            pre_distance_i_j = distance[0]
            distance[0] = i
            for j in xrange(1, len(word2) + 1):
                insert = distance[j - 1] + 1
                delete = distance[j] + 1
                replace = pre_distance_i_j
                if word1[i - 1] != word2[j - 1]:
                    replace += 1
                pre_distance_i_j = distance[j]
                distance[j] = min(insert, delete, replace)

        return distance[-1]


