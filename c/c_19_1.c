/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fir, *sec, dummy;
    dummy.next = head;
    fir = &dummy;
    sec = &dummy;
    
    while (n-- > 0) {
        fir = fir->next;
    }
    
    while(fir->next != NULL) {
        fir = fir->next;
        sec = sec->next;
    }
    sec->next = sec->next->next;
    return dummy.next;
}

