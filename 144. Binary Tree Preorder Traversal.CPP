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

// Method 1 : Recursive Approach

class Solution {
private:
    vector<int> output;
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if (root == nullptr)
            return output;
        
        preorde_traversal(root);
        return output;
    }

private:
    void preorde_traversal(TreeNode* node) {
        
        if (node == nullptr)
            return;
        
        output.push_back(node -> val);
        preorde_traversal(node -> left);
        preorde_traversal(node -> right);
    }
};

// Method 2 Iterative Approach

class Solution {
private:
    vector<int> output;
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if (root == nullptr)
            return output;
        
        stack<TreeNode*> Stack;
        Stack.push(root);
        
        while (!Stack.empty()) 
        {
            TreeNode* node = Stack.top(); Stack.pop();
            int val = node -> val;
            
            if (node -> right != nullptr)
                Stack.push(node -> right);
            
            output.push_back(val);
            
            if (node -> left != nullptr)
                Stack.push(node -> left);
        }
        
        return output;
    }
};

// Method 3 Iterative Approach

class Solution {
private:
    vector<int> output;
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if (root == nullptr)
            return output;
        
        TreeNode* node = root;
        stack<TreeNode*> Stack;
            
        while (true)
        {
            while (node != nullptr)
            {
                int val = node -> val;
                Stack.push(node);
                output.push_back(val);
                
                node = node -> left;
            }
            
            if (Stack.empty())
                break;
            
            node = Stack.top(); Stack.pop();
            node = node -> right;
        }
            
        return output;
    }
};
