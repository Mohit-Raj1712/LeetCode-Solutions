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
    bool isValidBST(TreeNode* root) {
        
        long Left_Pointer = LONG_MIN;
        long Right_Pointer = LONG_MAX;
        
        return isValidBST(root, Left_Pointer, Right_Pointer);
    }
    
    bool isValidBST(TreeNode* root, long Left_Pointer, long Right_Pointer) {
        
        if(root == nullptr) return true;
        
        if(Left_Pointer < root -> val && root -> val < Right_Pointer)
            return isValidBST(root -> left, Left_Pointer, root -> val) && isValidBST(root -> right, root -> val, Right_Pointer);
        
        return false;
            
    }
    
};

class checkBST {
public:    
    bool isBST;
    long long int min, max;
    
public:
    checkBST(long long int min, long long int max, bool isBST) {
        
        this -> min = min;
        this -> max = max;
        this -> isBST = isBST;
    }
};

// ----------------------------------------------------------------------------

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return validateBST(root) -> isBST;
    }
    
private:
    
    checkBST* validateBST(TreeNode* root) {
        
        if(root == nullptr) return new checkBST(LONG_MAX, LONG_MIN, true);
        
        checkBST* leftSubTree = validateBST(root -> left);
        checkBST* rightSubTree = validateBST(root -> right);
        
        bool isBST = leftSubTree -> isBST && rightSubTree -> isBST && (leftSubTree -> max < root -> val && root -> val < rightSubTree -> min);
        
        long long int min = fmin(root -> val, fmin(leftSubTree -> min, rightSubTree -> min));
        long long int max = fmax(root -> val, fmax(leftSubTree -> max, rightSubTree -> max));
        
        return new checkBST(min, max, isBST);
    }
};