/*
 * @Author: AGOGIN
 * @Date: 2019-11-12 15:34:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-12 15:39:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int findLUSlength(char * a, char * b){
    int aNum = strlen(a), bNum = strlen(b);
    if (aNum == bNum) {
        int i = 0;
        while (a[i] != '\0') {
            if (a[i] != b[i]) return aNum;
            i++;
        }
        return -1;
    } else return aNum > bNum ? aNum : bNum;
}

int main() {

    return 0;
}