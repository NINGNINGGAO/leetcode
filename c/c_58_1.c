#include <stdio.h>
#include <stdlib.h>

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