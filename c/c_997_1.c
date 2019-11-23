/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 21:56:47
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 22:25:50
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int* outDegree = malloc(sizeof(int) * (N + 1));
    int* inDegree = malloc(sizeof(int) * (N + 1));
    memset(outDegree, 0, sizeof(int) * (N + 1));
    memset(inDegree, 0, sizeof(int) * (N + 1));
    for (int i = 0; i < trustSize; i++) {
        inDegree[trust[i][1]]++;
        outDegree[trust[i][0]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] + 1 == N && outDegree[i] == 0) return i;
    }
    return -1;
}

int main() {

    return 0;
}