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
    vector<string> output;
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s = "";
        allpaths(root, s);
        
        return output;
    
    }
    
    void allpaths(TreeNode* root, string& s) {
        
        
        if(root -> left == nullptr && root -> right == nullptr)
        {
            s += to_string(root -> val);
            output.push_back(s);
            return;
        }
        
        string l = s + to_string(root -> val) + "->";
        string r = l;
        
        if(root -> left != nullptr)
            allpaths(root -> left, l);
        
        if(root -> right != nullptr)
            allpaths(root -> right, r);
            
        return;
    }
    
};