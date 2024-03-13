/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode *node, int *i, int *ret_val) {
    if (node == NULL)
        return;
    inorder(node->left, i, ret_val);
    ret_val[(*i)++]=node->val;
    inorder(node->right, i, ret_val);
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int cnt=0;
    void counttraverse(struct TreeNode* node) {
        if (node==NULL)
            return;
        counttraverse(node->left);
        cnt++;
        counttraverse(node->right);
        return;
    }
    counttraverse(root);
    printf("%d", cnt);
    int *ret_val = (int *)malloc(cnt * sizeof(int));
    int idx = 0;
    inorder(root, &idx, ret_val);
    *returnSize = idx;
    return ret_val;
}
