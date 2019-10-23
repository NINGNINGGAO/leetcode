/*
 * @Author: AGOGIN
 * @Date: 2019-10-23 15:53:36
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-23 17:26:44
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0;
    struct ListNode *AMid = headA, *BMid = headB, *ret = NULL;
    while (AMid != NULL) {
        lenA++;
        AMid = AMid->next;
    }
    while (BMid != NULL) {
        lenB++;
        BMid = BMid->next;
    }
    AMid = headA;
    BMid = headB;
    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) {
            AMid = AMid->next;
        }
    } else if (lenB > lenA) {
        for (int i = 0; i < lenB - lenA; i++) {
            BMid = BMid->next;
        }
    }
    while (BMid && AMid) {
        if (AMid == BMid) {
            ret = AMid;
            break;
        }
        AMid = AMid->next;
        BMid = BMid->next;
    }
    return ret;
}

int main() {

    return 0;
}