/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 15:53:51
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 11:48:04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct StrListNode {
    char* list;
    int index;
};
int cmp(const void* a, const void* b) {
    return strcmp((*((struct StrListNode*)a)).list, (*((struct StrListNode*)b)).list);
}
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    *returnSize = 0;
    if (list1Size <= 0) return NULL;
    if (list2Size <= 0) return NULL;
    struct StrListNode* list1Node = malloc(sizeof(struct StrListNode) * list1Size);
    struct StrListNode* list2Node = malloc(sizeof(struct StrListNode) * list2Size);
    for (int i = 0; i < list1Size; i++) {
        (list1Node[i]).list = list1[i];
        (list1Node[i]).index = i;
    }
    for (int i = 0; i < list2Size; i++) {
        (list2Node[i]).list = list2[i];
        (list2Node[i]).index = i;
    }
    qsort(list1Node, list1Size, sizeof(struct StrListNode), cmp);
    qsort(list2Node, list2Size, sizeof(struct StrListNode), cmp);
    int i = 0, j = 0;
    int minlistSize = list1Size < list2Size ? list1Size : list2Size;
    int** storage = malloc(sizeof(int*) * minlistSize);
    int storageSize = 0;
    while (i < list1Size && j < list2Size) {
        int temp = strcmp(list1Node[i].list, list2Node[j].list);
        if (temp == 0) {
            storage[storageSize] = malloc(sizeof(int) * 2);
            storage[storageSize][0] = i;
            storage[storageSize][1] = list1Node[i].index + list2Node[j].index;
            storageSize++;
            i++;
            j++;
        } else if (temp > 0) j++;
        else if (temp < 0) i++;
    }
    int minIndex = storage[0][1];
    for (int k = 1; k < storageSize; k++) {
        if (storage[k][1] < minIndex) minIndex = storage[k][1];
    }
    char** res = malloc(sizeof(char*) * storageSize);
    for (int k = 0; k < storageSize; k++) {
        if (storage[k][1] == minIndex) {
            int sLen = strlen(list1Node[storage[k][0]].list) + 1;
            res[*returnSize] = malloc(sizeof(char) * sLen);
            memset(res[*returnSize], 0, sizeof(char) * sLen);
            res[*returnSize] = strcpy(res[*returnSize], list1Node[storage[k][0]].list);
            (*returnSize)++;
        }
    }
    return res;
}


int main() {
    int a[] = {1,2,3,4,5,6};
    int s1Size = 3;
    char** s1 = malloc(sizeof(char*) * s1Size);
    for (int i = 0; i < s1Size; i++) {
        s1[i] = malloc(sizeof(char) * 20);
        memset(s1[i], 0, sizeof(char) * 20);
    }
    s1[0] = "rbp";
    s1[1] = "hyzn";
    s1[2] = "KFC";

    int s2Size = 2;
    char** s2 = malloc(sizeof(char*) * s2Size);
    for (int i = 0; i < s2Size; i++) {
        s2[i] = malloc(sizeof(char) * 50);
        memset(s2[i], 0, sizeof(char) * 50);
    }
    s2[0] = "rbp";
    s2[1] = "KFC";

    int returnSize;
    char** res = findRestaurant(s1, s1Size, s2, s2Size, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}