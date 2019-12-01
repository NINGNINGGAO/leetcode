/*
 * @Author: AGOGIN
 * @Date: 2019-12-01 11:43:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 13:54:59
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * multiply(char * num1, char * num2){
    int aLen = strlen(num1), bLen = strlen(num2);
    if ((aLen == 1 && num1[0] == '0') || (bLen == 1 && num2[0] == '0')) return "0";
    int* nums = malloc(sizeof(int) * (aLen + bLen));
    memset(nums, 0, sizeof(int) * (aLen + bLen));
    for (int i = aLen - 1; i >= 0; i--) {
        int left = num1[i] - '0';
        for (int j = bLen - 1; j >= 0; j--) {
            int right = num2[j] - '0';
            int temp = left * right + nums[i + j + 1];
            nums[i + j + 1] = temp % 10;
            nums[i + j] += temp / 10;
        }
    }
    char* res = malloc(sizeof(char) * (aLen + bLen + 1));
    memset(res, 0, sizeof(char) * (aLen + bLen + 1));
    int count  = 0;
    for (int i = 0; i < (aLen + bLen); i++) {
        if (i == 0 && nums[i] == 0) continue;
        res[count++] = nums[i] + '0';
    }
    return res;
}

int main() {
    char s[] = "123";
    char p[] = "456";
    char* res = multiply(s, p);
    printf("%s\n", res);
    return 0;
}