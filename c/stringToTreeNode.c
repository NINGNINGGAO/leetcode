/*
 * @Author: AGOGIN 
 * @Date: 2020-03-14 23:43:01 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-19 16:43:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    char* s;
    struct ListNode* next;
};

struct ListNode* stringToListNode(char* s) {
    int sLen = strlen(s);
    if (sLen <= 2) return NULL;
    s[0] = ',';
    s[sLen - 1] = '\0';
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* pre = head;
    for (int i = 1; i < sLen; i++) {
        if (s[i - 1] == ',' && s[i] != '\0') {
            s[i - 1] = '\0';
            struct ListNode* temp = malloc(sizeof(struct ListNode));
            temp->next = NULL;
            temp->s = &(s[i]);
            pre->next = temp;
            pre = temp;
        }
    }
    return head;
}

struct TreeNode* listToTree(struct ListNode* head) {
    if (head->next == NULL) return NULL;
    struct ListNode* temp = head->next;
    struct TreeNode** preMat = malloc(sizeof(struct TreeNode*) * 1024);
    struct TreeNode** lastMat = malloc(sizeof(struct TreeNode*) * 1024);
    struct TreeNode** mid;
    int preNum = 0, lastNum = 0;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = atoi(temp->s);
    preMat[preNum++] = root;
    temp = temp->next;
    int flag = 0;
    while (temp != NULL) {
        if (flag >= 2 * preNum) {
            preNum = lastNum;
            lastNum = 0;
            mid = preMat;
            preMat = lastMat;
            lastMat = mid;
            flag = 0;
        } else {
            if (isalpha((temp->s)[0]) == false) {
                struct TreeNode* newBro = malloc(sizeof(struct TreeNode));
                newBro->left = NULL;
                newBro->right = NULL;
                newBro->val = atoi(temp->s);
                lastMat[lastNum++] = newBro;
                if (flag % 2 == 0) preMat[flag / 2]->left = newBro;
                else preMat[flag / 2]->right = newBro;
            }
            flag++;
            temp = temp->next;
        }
    }
    free(preMat);
    free(lastMat);
    return root;
}

int main() {
    char* s = malloc(sizeof(char) * 1024);
    scanf("%s", s);
    //char s[] = "[1,NULL,2,NULL,3,NULL,4,NULL,5,NULL,6,7,8]";
    struct ListNode* head = stringToListNode(s);
    struct TreeNode* root = listToTree(head);
    struct ListNode* temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
    free(s);
    
    return 0;
}