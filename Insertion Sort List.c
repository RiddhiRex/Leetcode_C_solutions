/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *curr,*prev, *cnxt;
    struct ListNode dummy;
    dummy.next = head;
    curr = head;
    
    while(curr) {
        cnxt = curr->next;
        prev = &dummy;
        while(prev->next!=NULL && prev->next->val<curr->val) {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next =curr;
        curr = cnxt;
    }
    return dummy.next;
}
