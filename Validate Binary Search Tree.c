/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode *node, int minval, int maxval){
    if (node==NULL)
        return true;
    if (node->val<=minval || node->val>=maxval) 
        return false;
    return dfs(node->left, minval, node->val) && dfs(node->right, node->val, maxval);
}
bool isValidBST(struct TreeNode* root) {
    return dfs(root, INT_MIN, INT_MAX);
}
