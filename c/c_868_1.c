/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 13:07:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 13:12:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int binaryGap(int N){
    int res = 0;
    int flag = INT_MAX;
    for (int i = 0; i < 31; i++) {
        if ((N >> i) & 1) {
            res = res > (i - flag) ? res : (i - flag);
            flag = i;
        }
    }
    return res;
}

int main() {

    return 0;
}