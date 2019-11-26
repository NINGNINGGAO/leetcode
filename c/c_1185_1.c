/*
 * @Author: AGOGIN
 * @Date: 2019-11-26 16:13:35
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-26 16:31:38
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * dayOfTheWeek(int day, int month, int year){
    if(month == 1 || month == 2) {
        month += 12;
        year--;
    }
    int W= (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    char temp[][10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    char* res = malloc(sizeof(char) * 10);
    memset(res, 0, sizeof(char) * 10);
    sprintf(res, "%s", temp[W]);
    return res;
}

int main() {
    int year = 0;
    int month = 0;
    for (int day = 0; day <= 10; day++) {
        int W= (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
        printf("%d\n", W);
    }
    return 0;
}