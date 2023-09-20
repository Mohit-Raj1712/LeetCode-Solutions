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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == nullptr)
            return nullptr;
        
        if (root == p || root == q)
            return root;
        
        TreeNode* left_subtree = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right_subtree = lowestCommonAncestor(root -> right, p, q);
        
        if (left_subtree != nullptr && right_subtree != nullptr)
            return root;
        
        return left_subtree != nullptr ? left_subtree : right_subtree;
    }
};