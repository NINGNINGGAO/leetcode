/*
 * @Author: AGOGIN
 * @Date: 2019-09-09 16:54:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-09 16:54:52
 */
#include <stdio.h>

int climbStairs(int n){
    if (n <= 0) return 0;
    int arr[n];
    switch (n) {
        case 1: return 1;
        case 2: return 2;
        default :
            arr[0] = 1;
            arr[1] = 2;
            for (int i = 2; i < n; i++) {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
            return arr[n - 1];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int ret = climbStairs(n);
    printf("%d\n", ret);
    return 0;
}