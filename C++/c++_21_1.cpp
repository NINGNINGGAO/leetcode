/*
 * @Author: AGOGIN 
 * @Date: 2020-05-01 11:14:03 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-05-01 11:17:03
 */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while ((l1 != NULL) && (l2 != NULL)) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1 != NULL) temp->next = l1;
        if (l2 != NULL) temp->next = l2;
        temp = head->next;
        delete head;
        return temp;
    }
};