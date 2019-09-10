/*
 * @Author: AGOGIN
 * @Date: 2019-09-06 11:04:59
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-06 15:03:21
 */
#include <stdio.h>

int uniquePaths(int m, int n){
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            a[j] = a[j] + a[j - 1];
        }
    }
    return a[n - 1];
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int ret = uniquePaths(m, n);
    printf("%d\n", ret);
    return 0;
}