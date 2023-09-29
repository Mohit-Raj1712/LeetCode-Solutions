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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> output;
        
        if (root == nullptr)
            return output;
        
        queue<TreeNode*> Queue;
        Queue.push(root);
        
        while (!Queue.empty())
        {
            int N = Queue.size();
            vector<int> temp;
            
            for (int i = 0; i < N; i++)
            {
                TreeNode* node = Queue.front(); Queue.pop();
                
                if (node -> left != nullptr)
                    Queue.push(node -> left);
                
                temp.push_back(node -> val);
                
                if (node -> right != nullptr)
                    Queue.push(node -> right);
            }
            
            output.push_back(temp);
        }
        
        return output;
    }
};