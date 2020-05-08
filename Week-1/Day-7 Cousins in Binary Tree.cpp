Day-7 Cousins in Binary Tree.cpp

/*

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.


*/

// Time:  O(n)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int depth_x = 0, depth_y = 0;
        TreeNode *parent_x = nullptr, *parent_y = nullptr;
        return dfs(root, x, &depth_x, &parent_x) &&
               dfs(root, y, &depth_y, &parent_y) &&
               depth_x == depth_y &&
               parent_x != parent_y;
    }
    
private:
    bool dfs(TreeNode *root, int x, int *depth, TreeNode **parent) {
        if (!root) {
            return false;
        }
        if (root->val == x) {
            return true;
        }
        ++(*depth);
        auto prev_parent = (*parent);
        (*parent) = root;
        if (dfs(root->left, x, depth, parent)) {
            return true;
        }
        (*parent) = root;
        if (dfs(root->right, x, depth, parent)) {
            return true;
        }
        (*parent) = prev_parent;
        --(*depth);
        return false;
    }
};