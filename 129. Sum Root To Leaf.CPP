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
public:
    int sumNumbers(TreeNode* root, int val = 0) {
        
        if (root == nullptr)
            return 0;
        
        if (root -> left == nullptr && root -> right == nullptr)
        {
            val = 10 * val + root -> val;
            return val;
        }
        
        return sumNumbers(root -> left, 10 * val + root -> val) + sumNumbers(root -> right, 10 * val + root -> val);
    }
};