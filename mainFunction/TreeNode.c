/*
 * @Author: AGOGIN 
 * @Date: 2020-03-14 23:43:01 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-18 23:13:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    char* s = malloc(sizeof(char) * 1024);
    scanf("%s", &s);
    printf("%s", s);
    return 0;
}