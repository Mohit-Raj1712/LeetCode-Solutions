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
    unordered_map<int, pair<int, int>> lookup;

public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        if (root == nullptr)
            return false;

        lookup[root -> val] = {-1, -1};
        
        find_parent(root, 0);        

        pair<int, int> p1 = lookup[x];
        pair<int, int> p2 = lookup[y];

        if (p1.first != p2.first && p1.second == p2.second)
            return true;
        
        return false;
    }

private:
    void find_parent(TreeNode* root, int level) {

        if (root == nullptr)
            return;
        
        if (root -> left != nullptr)
            lookup[ root -> left -> val ] = { root -> val, level };
        
        if (root -> right != nullptr)
            lookup[ root -> right -> val ] = { root -> val, level };

        find_parent(root -> left, level + 1);
        find_parent(root -> right, level + 1);

        return;
    }
};