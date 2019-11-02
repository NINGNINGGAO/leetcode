/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 10:32:42
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 10:50:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isUgly(int num){
    if (num <= 0) return false;
    while (num != 1) {
        if (num % 2 == 0) num /= 2;
        else if (num % 3 == 0) num /= 3;
        else if (num % 5 == 0) num /= 5;
        else return false;
    }
    return true;
}

int main() {

    return 0;
}