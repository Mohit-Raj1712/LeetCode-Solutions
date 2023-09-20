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
        
        int root_val = root -> val;
        
        if (root == p || root == q)
            return root;
        
        if (p -> val > root_val && q -> val > root_val)
            return lowestCommonAncestor(root -> right, p, q);
        
        if (p -> val < root_val && q -> val < root_val)
            return lowestCommonAncestor(root -> left, p, q);
        
        return root; 
    }
};