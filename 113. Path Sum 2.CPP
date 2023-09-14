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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<vector<int>> output; // output -> root to leaf paths
        vector<int> path;
        
        total_paths(root, target, output, path);
        
        return output;
    }

private:
    
    void total_paths(TreeNode* root, int target, vector<vector<int>> &output, vector<int> &path) {
        
        if(root == nullptr) return;
        
        path.push_back(root -> val);
        
        if(root -> left == nullptr and root -> right == nullptr)
            if(target - root -> val == 0)
                output.push_back(path);
        
        total_paths(root -> left, target - root -> val, output, path);
        total_paths(root -> right, target - root -> val, output, path);
        
        path.pop_back();
    }
    
};