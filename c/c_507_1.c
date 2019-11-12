/*
 * @Author: AGOGIN
 * @Date: 2019-11-12 09:50:26
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-12 09:54:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool checkPerfectNumber(int num){
    if (num == 1) return false;
    int res = 1;
    for (int i = 2; i < num / i; i++) {
        if (num % i == 0) {
            res += i;
            res += num / i;
        }
    }
    return (num == res);
}

int main() {
    int num = 28;
    bool res = checkPerfectNumber(num);
    return 0;
}