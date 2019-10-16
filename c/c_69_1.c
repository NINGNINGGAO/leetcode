/*
 * @Author: AGOGIN
 * @Date: 2019-10-16 22:46:28
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-16 22:54:48
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int mySqrt(int x){
    int i = 0;
    int j = x / 2 + 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        double ret = (double)mid * mid;
        if (ret == x) {
            return mid;
        } else if (ret < x) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return j;
}

int main() {
    int ret = mySqrt(10);
    printf("%d\n", ret);
    return 0;
}