/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:36:43
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:39:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}

typedef struct {
    bool used;
    bool result;
} gy;

bool isDp(gy arx[100][100], char *s, char *p, int i, int j) {
    if  (arx[i][j].used) return arx[i][j].result;

    if (strlen(p) == j) return (strlen(s) == i);

    bool flag = ((strlen(s) != i-1) && (p[j] == s[i] || p[j] == '.'));
    bool ans = false;
    if (j <= strlen(p) - 2 && p[j + 1] == '*') {
        ans = (isDp(arx, s, p, i, j + 2) || (flag && isDp(arx, s, p, i + 1, j)));
    } else {
        ans = flag && isDp(arx, s, p, i + 1, j + 1);
    }

    arx[i][j].used = true;
    arx[i][j].result = ans;

    return ans;
}

bool isMatch(char * s, char * p){
    gy arx[100][100] = {0};
    return isDp(arx, s, p, 0, 0);
}

