/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 12:02:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 12:15:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * largestTimeFromDigits(int* A, int ASize){
    int num = -1;
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < ASize; j++) {
            if (j != i) {
                for (int k = 0; k < ASize; k++) {
                    if (k != i && k != j) {
                        int m = 6 - i - j - k;
                        int hours = 10 * A[i] + A[j];
                        int mins = 10 * A[k] + A[m];
                        if (hours < 24 && mins < 60) {
                            num = num > (hours * 60 + mins) ? num : (hours * 60 + mins);
                        }
                    }
                }
            }
        }
    }
    if (num < 0) return "";
    char* res = malloc(sizeof(char) * 6);
    memset(res, 0, sizeof(char) * 6);
    int hours = num / 60;
    int mins = num % 60;
    if (hours < 10) sprintf(res, "0%d:", hours);
    else sprintf(res, "%d:", hours);
    if (mins < 10) sprintf(res, "%s0%d", res, mins);
    else sprintf(res, "%s%d", res, mins);
    return res;
}

int main() {

    return 0;
}