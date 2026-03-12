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
    vector<int> inorder;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if (root == nullptr)
            return inorder;
        
        this -> inorder_traversal(root);

        return inorder;
    }
private:
    void inorder_traversal(TreeNode* root) {

        if (root == nullptr)
            return;
        
        inorder_traversal(root -> left);
        this -> inorder.push_back(root -> val);
        inorder_traversal(root -> right);

        return;
    }
};