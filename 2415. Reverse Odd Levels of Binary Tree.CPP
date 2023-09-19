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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        reverseOddLevels(root -> left, root -> right, 1);
        return root;
    }
    
private:
    void reverseOddLevels(TreeNode* p, TreeNode* q, int level) {
        
        if (p == nullptr || q == nullptr)
            return;
        
        if (level % 2 == 1)
        {
            int temp = p -> val;
            p -> val = q -> val;
            q -> val = temp;
        }
        
        reverseOddLevels(p -> left, q -> right, level + 1);
        reverseOddLevels(p -> right, q -> left, level + 1);
    }
};