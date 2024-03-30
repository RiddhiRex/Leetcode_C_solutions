/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left==right)
        return head;
    struct ListNode *start, *end, *prev, *curr, *cnxt;
    int idx=0;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    curr = head;
    prev = dummy;
    while(curr!=NULL && idx<left-1) {
        prev = curr;
        curr = curr->next;
        idx+=1;
    }
    end = prev;
    start = curr;
    
    while(curr!=NULL && idx<right) {
        cnxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = cnxt;
        idx+=1;
    }
    printf("%d %d ", start->val, end->val);
    start->next = curr;
    end->next = prev;

    head = dummy->next;
    free(dummy);
    return head;
}
