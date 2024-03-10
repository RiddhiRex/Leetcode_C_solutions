/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode *root1, struct TreeNode *root2){
    if (root1==NULL && root2==NULL)
        return true;
    else if (root1==NULL || root2==NULL)
        return false;
    if(root1->val!=root2->val)
        return false;
    return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
        
}
bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
    
}
