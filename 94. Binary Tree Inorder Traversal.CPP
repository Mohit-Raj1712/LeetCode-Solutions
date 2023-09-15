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

// Approach 1 : Recursive Approach

class Solution {
private:
    vector<int> output;
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        inorder_traversal(root);
        
        return output;
    }
    
private:
    void inorder_traversal(TreeNode* root) {
        
        if (root == nullptr)
            return;
        
        inorder_traversal(root -> left);
        output.push_back(root -> val);
        inorder_traversal(root -> right);
    }
};

// Method 2 : Iterative Approach

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> output;
        
        if (root == nullptr)
            return output;
        
        stack<TreeNode*> Stack;
        TreeNode* node = root;
        
        while (true)
        {
            while (node != nullptr)
            {
                Stack.push(node);
                node = node -> left;
            }
            
            if (Stack.empty())
                break;
            
            node = Stack.top(); Stack.pop();
            output.push_back(node -> val);
            node = node -> right;
        }
        
        return output;
    }
};