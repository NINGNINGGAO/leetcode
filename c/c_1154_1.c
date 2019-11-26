/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 22:19:47
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 22:37:20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    int year, month, day;
};
int dayOfYear(char * date){
    int res = 0;
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    date[4] = '\0';
    date[7] = '\0';
    struct Node* d = malloc(sizeof(struct Node));
    d->year = atoi(&(date[0]));
    d->month = atoi(&(date[5]));
    d->day = atoi(&(date[8]));
    if (d->year % 4 == 0 && d->year % 100 != 0 && d->month > 2) res++;
    for (int i = 0; i < (d->month) - 1; i++) {
        res += months[i];
    }
    res += d->day;
    return res;
}

int main() {
    char date[] = "2019-01-09";
    int res = dayOfYear(date);
    return 0;
}