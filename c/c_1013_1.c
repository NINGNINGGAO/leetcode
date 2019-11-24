/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 11:54:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 11:58:37
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }
    if (sum % 3 != 0) return false;
    int ave = sum / 3;
    int count = 0;
    int temp = 0;
    for (int i = 0; i < ASize; i++) {
        temp += A[i];
        if (temp == ave) {
            count++;
            temp = 0;
        }
    }
    if (count == 3) return true;
    return false;
}

int main() {

    return 0;
}