/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 09:27:01
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 09:34:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int maxDistToClosest(int* seats, int seatsSize){
    int max = 0, count = 0;;
    for (int i = 0; i < seatsSize; i++) {
        if (seats[i] == 0) count++;
        else {
            if (count > max) max = count;
            count = 0;
        }
    }
    int pMax = 0, bMax = 0;
    for (int i = 0; i < seatsSize; i++) {
        if (seats[i] == 0) pMax++;
        else break;
    }
    for (int i = seatsSize - 1; i >=0; i--) {
        if (seats[i] == 0) bMax++;
        else break;
    }
    int res = pMax > bMax ? pMax : bMax;
    max = (max + 1) / 2;
    res = res > max ? res : max;
    return res;
}

int main() {

    return 0;
}