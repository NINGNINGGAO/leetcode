/*
 * @Author: AGOGIN
 * @Date: 2019-11-05 22:21:47
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-06 10:20:10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * addStrings(char * num1, char * num2){
    int num1Size = strlen(num1);
    int num2Size = strlen(num2);
    int maxSize = num1Size > num2Size ? num1Size : num2Size;
    char* res = malloc(sizeof(char) * (maxSize + 2));
    int k = maxSize;
    res[k--] = '\0';
    int carry = 0, sum;
    for (int i = num1Size - 1, j = num2Size - 1; i >= 0 || j >= 0; i--, j--) {
        sum = carry;
        sum += (i >= 0) ? (num1[i] - '0') : 0;
        sum += (j >= 0) ? (num2[j] - '0') : 0;
        res[k--] = sum % 10 + '0';
        carry = sum / 10;
    }
    if (carry == 0) return res;
    else {
        for (int i = maxSize; i >= 0; i--) {
            res[i + 1] = res[i];
        }
        res[0] = '1';
        return res;
    }
}

int main() {
    char num1[] = "0";
    char num2[] = "0";
    char* res = addStrings(num1, num2);
    return 0;
}