/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 10:33:59
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 10:43:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define maxSize 10000
int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}
bool hasGroupsSizeX(int* deck, int deckSize){
    int* map = malloc(sizeof(int) * maxSize);
    memset(map, 0, sizeof(int) * maxSize);
    for (int i = 0; i < deckSize; i++) {
        map[deck[i]]++;
    }
    int g = -1;
    for (int i = 0; i < maxSize; i++) {
        if (map[i] > 0) {
            if (g == -1) {
                g = map[i];
            } else {
                g = gcd(g, map[i]);
            }
        }
    }
    return g >= 2;
}

int main() {

    return 0;
}