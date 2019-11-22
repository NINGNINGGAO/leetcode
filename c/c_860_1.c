/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 12:55:04
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 13:00:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool lemonadeChange(int* bills, int billsSize){
    if (billsSize == 0) return true;
    int flag[2] = {0};
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) flag[0]++;
        else if (bills[i] == 10) {
            if (flag[0] < 1) return false;
            else {
                flag[0]--;
                flag[1]++;
            }
        } else {
            if (flag[0] < 1) return false;
            else if (flag[0] < 3 && flag[1] < 1) return false;
            else if (flag[1] > 0) {
                flag[1]--;
                flag[0]--;
            } else if (flag[1] < 1) {
                flag[0] -= 3;
            }
        }
    }
    return true;
}

int main() {

    return 0;
}