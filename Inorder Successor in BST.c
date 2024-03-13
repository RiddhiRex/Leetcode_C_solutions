/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    if(root==NULL) {
        return NULL;
    }
    struct TreeNode *curr = root, *succ=NULL;
    while(curr!=NULL) {
        if(curr->val>p->val) {
            succ = curr;
            curr=curr->left;
        } else {
            curr = curr->right;
        }
            
    }
    return succ;
}
