/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 21:37:07
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 21:47:53
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    return !(rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
}

int main() {

    return 0;
}