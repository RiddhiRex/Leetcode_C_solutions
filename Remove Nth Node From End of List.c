/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int cnt = 0, idx=0;
    struct ListNode *prev= (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy = prev;
    prev->val = -1;
    prev->next = NULL;
    struct ListNode *curr = head;
    prev->next = curr;
    while(curr) {
        cnt+=1;
        curr = curr->next;
    }
    curr = head;
    while(curr->next!=NULL && idx<cnt-n) {
        prev = curr;
        curr=curr->next;
        idx+=1;
    }
    prev->next = curr->next;
    head = dummy->next;
    free(dummy);
    return head;
    
}
