/*
 * @Author: AGOGIN
 * @Date: 2019-11-04 09:35:16
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-04 09:40:29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isPerfectSquare(int num){
    if (num == 1) return true;
    int res = 1;
    int temp = 1;
    while (res < num && INT_MAX - res > temp) {
        temp += 2;
        res += temp;
    }
    if (res == num) return true;
    else return false;
}

int main() {

    return 0;
}