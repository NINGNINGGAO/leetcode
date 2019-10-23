/*
 * @Author: AGOGIN
 * @Date: 2019-10-23 10:22:57
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-23 10:31:24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0) return 0;
    int ret = 0;
    int min = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < prices[i - 1]) {
            ret += prices[i - 1] - min;
            min = prices[i];
        }
    }
    ret += prices[pricesSize - 1] - min;
    return ret;
}

int main() {
    int prices[] = {1,2,3,4,5};
    int ret = maxProfit(prices, 5);
    return 0;
}