/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 15:34:33
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 15:35:32
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int minCostToMoveChips(int* chips, int chipsSize){
    int odd = 0, even = 0;
    for (int i = 0; i < chipsSize; i++) {
        if (chips[i] % 2 == 0) even++;
        else odd++;
    }
    return even < odd ? even : odd;
}

int main() {

    return 0;
}