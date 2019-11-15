/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:37:20
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:43:46
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}
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

