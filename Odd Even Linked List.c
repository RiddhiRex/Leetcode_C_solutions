/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL)
        return NULL;
    struct ListNode *oddhead = NULL;
    struct ListNode *evenhead = NULL;
    int cnt = 1;
    oddhead = head;
    evenhead = head->next;
    struct ListNode *evencurr = evenhead;
    struct ListNode *oddcurr = oddhead;
    while(evencurr && evencurr->next) {
        oddcurr->next = evencurr->next;
        evencurr->next = evencurr->next->next;
        oddcurr = oddcurr->next;
        evencurr = evencurr->next;
    }
    oddcurr->next = evenhead;
    return oddhead;
}
