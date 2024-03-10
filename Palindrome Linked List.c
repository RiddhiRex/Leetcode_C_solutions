/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode *curr){
    struct ListNode *prev=NULL, *cnxt;
    while(curr!=NULL){
        cnxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=cnxt;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    if (head==NULL || head->next==NULL)
        return true;
    struct ListNode *slow=head, *fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("%d \n", slow->next->val);
    slow->next=reverseList(slow->next);
    printf("%d \n", slow->next->val);
    struct ListNode *p1=head, *p2=slow->next;
    while(p2!=NULL){
        printf("%d %d\n", p1->val, p2->val);
        if (p1->val!=p2->val)
            return false;
        p1=p1->next;
        p2=p2->next;
    }
    return true;
    
}
