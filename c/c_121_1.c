/*
 * @Author: AGOGIN
 * @Date: 2019-10-23 10:09:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-23 10:13:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0) return 0;
    int min = prices[0], ret = 0;
    int temp;
    for (int i = 1; i < pricesSize; i++) {
        if (min > prices[i]) {
            min = prices[i];
        } else {
            temp = prices[i] - min;
            ret = ret < temp ? temp : ret;
        }
    }
    return ret;
}

int main() {

    return 0;
}