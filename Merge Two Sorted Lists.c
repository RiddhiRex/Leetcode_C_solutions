/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL && list2==NULL)
        return NULL;
    if(list1==NULL)
        return list2;
    else if(list2==NULL)
        return list1;
    struct ListNode dummy;
    struct ListNode* prev= &dummy;
    while(list1!=NULL && list2!=NULL) {
        if(list1->val<list2->val) {
            prev->next=list1;
            list1=list1->next;
        } else {
            prev->next=list2;
            list2=list2->next;
        }
        prev=prev->next;
    }
    if (list1)
        prev->next=list1;
    else if(list2)
        prev->next=list2;
    return dummy.next;
}
