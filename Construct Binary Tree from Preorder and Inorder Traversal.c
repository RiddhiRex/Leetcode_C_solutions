/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* build(int* preorder, int po_start, int po_end, int* inorder, int ino_start, int ino_end) {
     if(ino_start>ino_end || po_start>po_end)
        return NULL;
     struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
     root->val=preorder[po_start];
     int idx=ino_start;
     while(idx<=ino_end && root->val!=inorder[idx])
        idx++;
    int leftSubtreeSize = idx - ino_start;
    root->left = build(preorder,po_start+1, po_start+leftSubtreeSize, inorder, ino_start, idx-1);
    root->right = build(preorder,po_start+leftSubtreeSize+1, po_end, inorder, idx+1, ino_end);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1);
}
