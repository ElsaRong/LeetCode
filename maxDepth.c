/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if (NULL == root)
        return 0 ;
    
    return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}
