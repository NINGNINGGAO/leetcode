/*
 * @Author: AGOGIN 
 * @Date: 2020-03-22 00:07:00 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-22 00:28:14
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize){
    int dp_i10 = 0, dp_i11 = INT_MIN;
    int dp_i20 = 0, dp_i21 = INT_MIN;
    for (int i = 0; i < pricesSize; i++) {
        dp_i20 = Max(dp_i20, dp_i21 + prices[i]);
        dp_i21 = Max(dp_i21, dp_i10 - prices[i]);
        dp_i10 = Max(dp_i10, dp_i11 + prices[i]);
        dp_i11 = Max(dp_i11, -prices[i]);
    }
    return dp_i20;
}

int main() {
    
    return 0;
}