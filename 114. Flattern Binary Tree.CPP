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
    void flatten(TreeNode* root) {
        
        if(root == nullptr)
            return;
        
        stack<TreeNode*> Stack;
        Stack.push(root);
        
        while(!Stack.empty()) {
            
            TreeNode* node = Stack.top(); Stack.pop();
            
            if(node -> right != nullptr)
                Stack.push(node -> right);
            
            if(node -> left != nullptr)
                Stack.push(node -> left);
            
            node -> left = nullptr;
            node -> right = !Stack.empty() ? Stack.top() : nullptr;
        
        }
        
        return;
    }

};