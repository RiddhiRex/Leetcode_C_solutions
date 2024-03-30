/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool traverse(struct TreeNode *node, int total, int targetsum) {
    bool leftret = false, rightret = false;
    if (node->left==NULL && node->right==NULL) 
        if(total==targetsum)
            return true;
    if(node->left)
        leftret =traverse(node->left, total+node->left->val, targetsum);
    if(node->right)
        rightret =traverse(node->right, total+node->right->val, targetsum);
    return leftret || rightret;
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root==NULL)
        return false;
    return traverse(root, root->val, targetSum);

}
