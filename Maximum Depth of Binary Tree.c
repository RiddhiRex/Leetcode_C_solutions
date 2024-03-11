/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int dfs(struct TreeNode *node, int depth, int maxdepth) {
    if(node->left==NULL && node->right==NULL) {
        maxdepth = (depth> maxdepth)?depth: maxdepth;
        return maxdepth;
    }
    if(node->left) {
        int left_max = dfs(node->left, depth+1, maxdepth);
        maxdepth = (left_max>maxdepth)?left_max:maxdepth;
    } 
    if(node->right) {
        int right_max = dfs(node->right, depth+1, maxdepth);
        maxdepth = (right_max>maxdepth)?right_max:maxdepth;
    }
    return maxdepth;
 }  

int maxDepth(struct TreeNode* root) {
    if(root==NULL)
        return 0;
    return dfs(root, 1, 1);
}
