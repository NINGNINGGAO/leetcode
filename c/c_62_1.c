/*
 * @Author: AGOGIN
 * @Date: 2019-09-06 10:49:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-06 11:04:43
 */
#include <stdio.h>

int uniquePaths(int m, int n){
    if (m <= 0 || n <= 0) {
        return 0;
    } else if (m == 1 && n == 1) {
        return 1;
    } else if (m == 2 && n == 1) {
        return 1;
    } else if (m == 1 && n == 2) {
        return 1;
    }
    int num = 0;
    num += uniquePaths(m - 1, n);
    num += uniquePaths(m, n - 1);
    return num;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int ret = uniquePaths(m, n);
    printf("%d\n", ret);
    return 0;
}