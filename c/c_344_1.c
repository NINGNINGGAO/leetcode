/*
 * @Author: AGOGIN
 * @Date: 2019-11-03 10:49:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-03 10:57:26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void reverseString(char* s, int sSize){
    int slow = 0, fast = sSize - 1;
    char temp;
    while (slow < fast) {
        temp = s[slow];
        s[slow++] = s[fast];
        s[fast--] = temp;
    }
}

int main() {

    return 0;
}