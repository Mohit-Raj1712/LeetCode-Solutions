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

// Iterative Approach

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
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
                Stack.push(node);
                node = node -> left;
            }
            
            if (Stack.empty())
                break;
            
            node = Stack.top(); Stack.pop();
            if (!Stack.empty() && Stack.top() == node)
                node = node -> right;
            
            else {
                output.push_back(node -> val);
                node = nullptr;
            }
        }
        
        return output;
    }
};

// Recursive Approach 

class Solution {
private:
    vector<int> output;

public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        postorder_traversal(root);
        return output;
    }
    
private:
    void postorder_traversal(TreeNode* node) {
        
        if (node == nullptr)
            return;
        
        postorder_traversal(node -> left);
        postorder_traversal(node -> right);
        output.push_back(node -> val);
    }
};