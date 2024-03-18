/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
   if(head==NULL) {
        return NULL;
    }
	struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr1 = head;
    struct Node* curr2;
    while(curr1) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr1->val;
        newNode->next = curr1->next;
        curr1->next = newNode;
        curr1 = newNode->next;
    }

    curr1 = head;
    while(curr1) {
        if(curr1->random) {
            curr1->next->random = curr1->random->next;
        }
        else {
            curr1->next->random = NULL;
        }
        curr1 = curr1->next->next;
    }
    curr1 = head;
    while(curr1) {
        printf("%d ", curr1->val);
        curr1 = curr1->next;
    }
    curr1 = head;
    curr2 = head->next;
    head2 = head->next;
    while(curr1 && curr1->next) {
        curr1->next = curr1->next->next;
        if(curr2->next) {
            curr2->next = curr2->next->next;
        } 
        curr1=curr1->next;
        curr2=curr2->next;  
    }
    return head2;

}
