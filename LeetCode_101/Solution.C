/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool is_symmetric(struct TreeNode* p, struct TreeNode* q);

bool isSymmetric(struct TreeNode* root) {

    if (root == NULL)
        return true;

    return is_symmetric(root -> left, root -> right);    
}

bool is_symmetric(struct TreeNode* p, struct TreeNode* q) {

    if (p == NULL && q == NULL)
        return true;
    
    if (p == NULL || q == NULL)
        return false;
    
    if (p -> val != q -> val)
        return false;
    
    return is_symmetric(p -> left, q -> right) && is_symmetric(p -> right, q -> left);
}