Day-3 Ransom Note.cpp

/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> magazineHash(26,0);
        //Traverse magazine and keep count of each letter in magazineHash
        for(int i=0;magazine[i]!='\0';++i)
            magazineHash[magazine[i]-'a'] += 1;
        
        //Now traverse ransomNote and keep decrementing count in magazineHash
        for(int i=0;ransomNote[i]!='\0';++i)
        {
            if(magazineHash[ransomNote[i]-'a']==0)
                return false;
            magazineHash[ransomNote[i]-'a'] -= 1;   //Using up char will lead to decrementing it by value 1
        }
        return true;
    }
};
