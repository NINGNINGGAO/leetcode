/*
 * @Author: AGOGIN
 * @Date: 2019-10-30 16:00:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-30 16:07:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    struct ListNode* temp;
    temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
}

int main() {

    return 0;
}