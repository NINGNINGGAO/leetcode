/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 11:37:33
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 15:07:32
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isGoodNum(int num) {
    int map[] = {1,1,2,0,0,2,2,0,1,2};
    int flag = 0;
    while (num != 0) {
        if (map[num % 10] == 0) return false;
        else if (map[num % 10] == 2) flag = 1;
        num /= 10;
    }
    if (flag == 1) return true;
    return false;
}
int rotatedDigits(int N){
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (isGoodNum(i) == true) res++;
    }
    return res;
}

int main() {

    return 0;
}