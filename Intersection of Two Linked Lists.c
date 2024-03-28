/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL || headB==NULL)
        return NULL;
    int cntA =0, cntB = 0, diff=0;
    struct ListNode *intersection=NULL;
    struct ListNode *currA, *currB;
    currA =headA;
    currB = headB;
    while(currA) {
        cntA +=1;
        currA =currA->next;
    }
    while(currB) {
        cntB +=1;
        currB =currB->next;
    }
    currA =headA;
    currB = headB;   
    diff = abs(cntA-cntB);
    if(cntA>cntB) {
        while(diff>0) {
            currA = currA->next;
            diff-=1;
        }
    } else {
         while(diff>0) {
            currB = currB->next;
            diff-=1;
        }       
    }
    while(currA && currB) {
        if (currA == currB) {
            if(intersection==NULL)
                intersection = currA;
        } else {
            intersection = NULL;
        }
        currA =currA->next;
        currB = currB->next;
    }
    return intersection;
}
