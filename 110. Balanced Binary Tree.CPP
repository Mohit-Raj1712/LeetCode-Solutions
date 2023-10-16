/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    class checkBalance {
    
    public:
        int height;
        bool is_balanced;
        
    public:
        checkBalance(int height, bool is_balanced) {
            
            this -> height = height;
            this -> is_balanced = is_balanced;
        }        
    };
    
    
public:
    bool isBalanced(TreeNode* root) {
        
        bool output = balanced_binary_tree(root) -> is_balanced;
        return output;
    }

private:
    checkBalance* balanced_binary_tree(TreeNode* root) {
        
        if (root == nullptr)
            return new checkBalance(0, true);
            
        checkBalance* is_leftsubtree_balanced = balanced_binary_tree(root -> left);
        checkBalance* is_rightsubtree_balanced = balanced_binary_tree(root -> right);
        
        int left_subtree_height = is_leftsubtree_balanced -> height;
        int right_subtree_height = is_rightsubtree_balanced -> height;
        int height = max(left_subtree_height, right_subtree_height) + 1;
        
        bool balance_factor = abs(left_subtree_height - right_subtree_height) <= 1;
        bool is_tree_balanced = (is_leftsubtree_balanced -> is_balanced && is_rightsubtree_balanced -> is_balanced) && balance_factor;
        
        return new checkBalance(height, is_tree_balanced);
    }
};
