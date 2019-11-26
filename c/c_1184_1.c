/*
 * @Author: AGOGIN
 * @Date: 2019-11-26 15:15:12
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-26 16:12:10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int temp1 = 0, temp2 = 0;
    int temp;
    if (start > destination) {
        temp =start;
        start = destination;
        destination = temp;
    }
    for (int i = start; i < destination; i++) {
        temp1 += distance[i];
    }
    for (int i = destination; i < distanceSize; i++) {
        temp2 += distance[i];
    }
    for (int i = 0; i < start; i++) {
        temp2 += distance[i];
    }
    return temp1 < temp2 ? temp1 : temp2;
}

int main() {

    return 0;
}