/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traverse_inorder(struct TreeNode *node, int k, int *cnt, int *res) {
    if (node==NULL)
        return;
    traverse_inorder(node->left, k, cnt, res);
    *cnt+=1;
    if(k==*cnt) {
        *res = node->val;
        return;
    }
    traverse_inorder(node->right, k, cnt, res);
    return;
    
}
int kthSmallest(struct TreeNode* root, int k) {
    int res = 0;
    int cnt = 0;
    traverse_inorder(root, k, &cnt, &res);
    return res;
}
