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
    int val = 0;
    int counter = 0;
    
public:
    int kthSmallest(TreeNode* root, int k) {
        
        smallest_element(root, k);
        
        return val;
    }
    
private:
    void smallest_element(TreeNode* node, int k) {
        
        if (node == nullptr)
            return;
        
        smallest_element(node -> left, k);
        
        ++ counter;
        if (counter == k)
        {
            val = node -> val;
            return;
        }
        
        smallest_element(node -> right, k);
    }
};