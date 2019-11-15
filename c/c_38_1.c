/*
 * @Author: AGOGIN
 * @Date: 2019-08-20 13:11:50
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:42:05
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}

char * countAndSay(int n){
    char *ret = malloc(sizeof(char) * 500);
    char temp[500];
    ret[0] = '1';
    ret[1] = '\0';
    int count = 1;
    int mid = 0, j = 0;
    for (int i = 1; i < n; i++) {
        while (ret[j] != '\0') {
            if (ret[j] == ret[j + 1]) {
                count++;
            } else {
                temp[mid++] = count + '0';
                temp[mid++] = ret[j];
                count = 1;
            }
            j++;
        }
        temp[mid] = '\0';
        ret = strcpy(ret, temp);
        mid = 0;
        j = 0;
        count = 1;
    }
    return ret;
}

main() {
    char *p = malloc(sizeof(char) * 500);
    p = countAndSay(25);
    printf("%s\n", p);
}