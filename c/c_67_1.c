/*
 * @Author: AGOGIN
 * @Date: 2019-10-16 16:38:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-16 18:23:08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char * addBinary(char * a, char * b){
    int k = 0;
    int aNum = 0, bNum = 0;
    while (a[k] != '\0') {
        k++;
        aNum++;
    }
    k = 0;
    while (b[k] != '\0') {
        k++;
        bNum++;
    }
    if (aNum < bNum) {
        char* temp = a;
        a = b;
        b = temp;
        int mid = aNum;
        aNum = bNum;
        bNum = mid;
    }
    char* c = malloc(sizeof(char) * aNum);
    for (int i = 0; i < aNum - bNum; i++) {
        c[i] = '0';
    }
    int j = aNum - 1;
    for (int i = bNum - 1; i >= 0; i--) {
        c[j--] = b[i];
    }
    char* ret = malloc(sizeof(char) * (aNum + 2));
    ret[0] = '1';
    ret[aNum + 1] = '\0';
    int flag = 0;
    int tmp;
    for (int i = aNum - 1; i >= 0; i--) {
        tmp = (int)(a[i] - '0') + (int)(c[i] - '0') + flag;
        if (tmp >= 2) {
            ret[i + 1] = (char)(tmp - 2 + '0');
            flag = 1;
        } else {
            ret[i + 1] = (char)(tmp + '0');
            flag = 0;
        }
    }
    if (flag == 0) {
        return ret + 1;
    } else {
        return ret;
    }
}

int main() {
    char* a = "11";
    char* b = "1";
    char* ret = addBinary(a, b);
    printf("%s\n", ret);
    return 0;
}