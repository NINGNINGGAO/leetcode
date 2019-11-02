/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 16:10:32
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 17:23:38
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))
char * getHint(char * secret, char * guess){
    char* res = malloc(sizeof(char) * 10);
    res[4] = 0;
    int res1 = 0, res2 = 0;
    int i = 0;
    while (secret[i] != '\0') {
        if (secret[i] == guess[i]) res1++;
        i++;
    }
    int *hash1, *hash2;
    hash1 = malloc(sizeof(int) * 10);
    hash2 = malloc(sizeof(int) * 10);
    memset(hash1, 0, sizeof(int) * 10);
    memset(hash2, 0, sizeof(int) * 10);
    int j = 0;
    while (secret[j] != '\0') {
        hash1[secret[j] - '0']++;
        hash2[guess[j] - '0']++;
        j++;
    }
    for (int k = 0; k < 10; k++) {
        res2 += Min(hash1[k], hash2[k]);
    }
    res2 -= res1;
    sprintf(res, "%dA%dB", res1, res2);
    return res;
}

int main() {
    char* secret = "00112233445566778899";
    char* guess = "16872590340158679432";
    char* res = getHint(secret, guess);
    printf("%s\n", res);
    return 0;
}