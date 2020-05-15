Day-7 Implement Trie (Prefix Tree).cpp

/*

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.


*/


// Time:  O(n), per operation
// Space: O(1)

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : is_string(false) {
        
    }
    bool is_string;
    unordered_map<char, TrieNode *> leaves;
};

class Trie {
public:
    Trie() {
        root_ = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto *cur = root_;
        for (const auto& c : word) {
            if (!cur->leaves.count(c)) {
                cur->leaves[c] = new TrieNode();
            }
            cur = cur->leaves[c];
        }
        cur->is_string = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto *node = childSearch(word);
        if (node) {
            return node->is_string;
        }
        return false;   
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return childSearch(prefix);
    }

    TrieNode *childSearch(const string& word) {
        auto *cur = root_;
        for (const auto& c : word) {
            if (cur->leaves.count(c)) {
                cur = cur->leaves[c];
            } else {
                return nullptr;
            }
        }
        return cur;
    }

private:
    TrieNode *root_;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
