/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 11:06:58
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 15:47:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return strcmp((*(char**)a), (*(char**)b));
}
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    *returnSize = 0;
    if (list1Size <= 0) return NULL;
    if (list2Size <= 0) return NULL;
    qsort(list1, list1Size, sizeof(char*), cmp);
    qsort(list2, list2Size, sizeof(char*), cmp);
    int i = 0, j = 0;
    int temp;
    int minListSize = list1Size < list2Size ? list1Size : list2Size;
    char** res = malloc(sizeof(char*) * minListSize);
    while (i < list1Size) {
        temp = strcmp(list1[i], list2[j]);
        if (temp == 0) {
            res[*returnSize] = malloc(sizeof(char) * (strlen(list1[i]) + 3));
            memset(res[*returnSize], 0, sizeof(char) * (strlen(list1[i]) + 3));
            res[*returnSize] = strcpy(res[*returnSize], list1[i]);
            (*returnSize)++;
            i++;
            j++;
            if (j >= list2Size) break;
        } else if (temp > 0) {
            j++;
            if (j >= list2Size) break;
        } else i++;
    }
    return res;
}

int main() {
    int s1Size = 4;
    char** s1 = malloc(sizeof(char*) * s1Size);
    for (int i = 0; i < s1Size; i++) {
        s1[i] = malloc(sizeof(char) * 20);
        memset(s1[i], 0, sizeof(char) * 20);
    }
    s1[0] = "Shogun";
    s1[1] = "Tapioca Express";
    s1[2] = "Burger King";
    s1[3] = "KFC";

    int s2Size = 4;
    char** s2 = malloc(sizeof(char*) * s2Size);
    for (int i = 0; i < s2Size; i++) {
        s2[i] = malloc(sizeof(char) * 50);
        memset(s2[i], 0, sizeof(char) * 50);
    }
    s2[0] = "Piatti";
    s2[1] = "The Grill at Torrey Pines";
    s2[2] = "Hungry Hunter Steakhouse";
    s2[3] = "Shogun";

    int returnSize;
    char** res = findRestaurant(s1, s1Size, s2, s2Size, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}