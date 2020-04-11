/*
 * @Author: AGOGIN 
 * @Date: 2020-04-11 15:24:59 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-11 15:29:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int fun(int K, int T) {//可以覆盖多少区间
    if (K == 1 || T == 1) return T + 1;
    return fun(K, T - 1) + fun(K - 1, T - 1);
}

int superEggDrop(int K, int N){
    int T = 1;//扔的次数
    while (fun(K, T) < N + 1) T++;
    return T;
}

int main() {
    
    return 0;
}