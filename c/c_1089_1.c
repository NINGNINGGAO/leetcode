/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 10:16:01
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 10:33:16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void duplicateZeros(int* arr, int arrSize){
    int fast = 0, slow = 0;
    int flag = 0;
    while (fast < arrSize) {
        flag = 0;
        if (arr[slow] == 0) fast++;
        if (fast < arrSize) {
            flag = 1;
            fast++;
            slow++;
        } else break;
    }
    int i = arrSize - 1;
    if (flag == 0) arr[i--] = arr[slow];
    slow--;
    while (i >= 0) {
        if (arr[slow] == 0) arr[i--] = arr[slow];
        if (i >= 0) arr[i--] = arr[slow--];
    }
}

int main() {

    return 0;
}