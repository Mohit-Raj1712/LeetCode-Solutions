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
    TreeNode* sortedArrayToBST(vector<int>& array) {
        
        int N = array.size();
        
        return buildTree(array, 0, N - 1);
    }
    
    TreeNode* buildTree(vector<int>& array, int left_pointer, int right_pointer) {
        
        if (left_pointer > right_pointer)
            return nullptr;

        int mid = left_pointer + (right_pointer - left_pointer) / 2;
        int val = array[mid];
        
        TreeNode* root = new TreeNode(val);
        root -> left = buildTree(array, left_pointer, mid - 1);
        root -> right = buildTree(array, mid + 1, right_pointer);
        
        return root;
    }
};