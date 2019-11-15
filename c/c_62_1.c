/*
 * @Author: AGOGIN
 * @Date: 2019-09-06 10:49:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:42:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}
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