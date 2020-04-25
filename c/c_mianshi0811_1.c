/*
 * @Author: AGOGIN 
 * @Date: 2020-04-23 23:46:40 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-23 23:49:04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int mod = 1000000007;

int waysToChange(int n){
    int ret = 0;
    for (int i = 0; i * 25 <= n; i++) {
        int rest = n - i * 25;
        int a = rest / 10;
        int b = rest % 10 / 5;
        ret = (ret + (long long)(a + 1) * (a + b + 1) % mod) % mod;
    }
    return ret;
}

int main() {
    
    return 0;
}