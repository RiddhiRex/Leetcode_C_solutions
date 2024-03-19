/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *cnxt, *tmp, *start, *end;
    int cnt;
    while(curr) {
        tmp = curr;
        cnt = 0;
        end = prev;
        start = curr;
        while(tmp!=NULL && cnt<k) {
            cnt+=1;
            tmp = tmp->next;
        }
        if(cnt<k || tmp==NULL)
            break;
        cnt = 0;
        while(curr && cnt<k) {
            cnxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = cnxt;
            cnt+=1;
        } 
        
        if(end ==NULL)
           head = prev; 
        else
            end->next = prev;
        start->next = curr;
    }
    return head;
}
