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
    int deepestLeavesSum(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        queue<TreeNode*> Queue;
        Queue.push(root);
        
        int Output = 0;
        
        while(!Queue.empty()) {
            
            int n = Queue.size();
            int sum = 0;
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = Queue.front();
                
                sum += node -> val;
                
                if(node -> left != nullptr)
                    Queue.push(node -> left);
                
                if(node -> right != nullptr)
                    Queue.push(node -> right);
                
                Queue.pop();
            }
            
            Output = sum;
        }
        
        return Output;
    }
};