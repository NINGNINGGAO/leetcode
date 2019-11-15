/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:37:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:42:21
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}

int lengthOfLastWord(char * s){
    int ret = 0;
    int flag = 0;
    while (*s != '\0') {
        if (flag == 1 && *s != ' ') {
            ret = 0;
        }
        if (*s == ' ') {
            flag = 1;
        } else {
            flag = 0;
            ret++;
        }
        s++;
    }
    return ret;
}


int main() {
    char* s = malloc(sizeof(char) * 20);
    s = "a ";
    int ret = lengthOfLastWord(s);
    printf("%d\n", ret);
    return 0;
}