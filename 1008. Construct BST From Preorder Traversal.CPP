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
    int N;
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        this -> N = preorder.size();
        
        return constructTree(preorder, 0, N - 1);
    }
    
private:
    TreeNode* constructTree(vector<int>& preorder, int left_pointer, int right_pointer) {
        
        if (left_pointer > right_pointer)
            return nullptr;
        
        int root_val = preorder[left_pointer];
        
        if (left_pointer == right_pointer)
            return new TreeNode(root_val);
        
        int index = left_pointer + 1;
        
        while (index < N && preorder[index] < preorder[left_pointer])
            index ++;
        
        TreeNode* root = new TreeNode(root_val);
        root -> left = constructTree(preorder, left_pointer + 1, index - 1);
        root -> right = constructTree(preorder, index, right_pointer);
        
        return root;
    }
};