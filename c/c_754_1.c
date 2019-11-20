/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 09:31:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 09:56:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int reachNumber(int target){
    if (target == 0) return 0;
    target = abs(target);
    int res = 1, sum = 1;
    while (sum < target || (sum + target) % 2 != 0) {
        res++;
        sum += res;
    }
    return res;
}

int main() {

    return 0;
}