/*
 * @Author: AGOGIN
 * @Date: 2019-08-18 20:29:09
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:41:20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    //创建一个临时头节点，避免链表头节点需要区分处理
    struct ListNode *point = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tmphead = head;
    point->next = head;
    head = point;


    //获取链表节点数量
    int cnt = 0;
    while (tmphead != NULL) {
        cnt++;
        tmphead = tmphead->next;
    }

    int i;
    struct ListNode *prev, *now, *tmp;
    while (point != NULL) {
        //判断剩下的节点数量是否足够
        if (cnt < k) {
            break;
        }

        //指定K个节点逆转
        tmphead = NULL;
        prev = point->next;
        now = point->next->next;
        for (i=0; i<k; i++) {
            prev->next = tmphead;
            tmphead = prev;
            prev = now;

            if (now != NULL) {
                now = now->next;
            }
        }
        //处理后的prev指针指向第K+1个节点或NULL

        //串联下部分节点：原第1个节点，现第K个节点，指向第K+1个节点或NULL
        point->next->next = prev;

        //暂存第K个节点（尾节点）
        tmp = point->next;

        //串联上部分节点，第一次操作时head指针对应临时节点的后继节点为链表的头节点
        point->next = tmphead;

        //point指针指向第K个节点，作为下一轮K个节点的临时前继节点
        point = tmp;

        //重新计算可用的剩余节点数量
        cnt = cnt - k;
    }
    //释放临时节点
    tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

main() {
    int i;
    for (i = 0; i < 5; i++);
    printf("%d\n",i);
}