/*
 * @Author: AGOGIN 
 * @Date: 2020-04-08 09:03:24 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-08 16:25:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int digitSum(int num) {
    int ret = 0;
    while (num != 0) {
        ret += num % 10;
        num = num / 10;
    }
    return ret;
}
int countNum(int num, int row, int col, int k) {
    int ret = 0;
    for (int i = 0; i < col; i++) {
        int temp = k - num - i + 1;
        temp = temp > 0 ? temp : 0;
        ret += temp > row ? row : temp;
    }
    return ret;
}

int movingCount(int m, int n, int k){
    if (k == 0) return 1;
    int ret = 0;
    for (int i = 0; i <= (m - 1) / 10; i++) {
        for (int j = 0; j <= (n - 1) / 10; j++) {
            int temp = digitSum(i * 10) + digitSum(j * 10);
            if (i == 0 && j == 0) ret += countNum(0, (i + 1) * 10 > m ? (m - i * 10) : 10, (j + 1) * 10 > n ? (n - j * 10) : 10, k);
            else if (i == 0 && digitSum(j * 10 - 1) <= k) {
                ret += countNum(digitSum(j * 10), (i + 1) * 10 > m ? (m - i * 10) : 10, (j + 1) * 10 > n ? (n - j * 10) : 10, k);
            } else if (i != 0 && digitSum(i * 10 - 1) + digitSum(j * 10) <= k) {
                ret += countNum(digitSum(i * 10) + digitSum(j * 10), (i + 1) * 10 > m ? (m - i * 10) : 10, (j + 1) * 10 > n ? (n - j * 10) : 10, k);
            }
        }
    }
    return ret;
}

int main() {
    int ret = movingCount(20,23,8);
    printf("%d\n", ret);
    return 0;
}