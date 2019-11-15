/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:36:35
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:39:16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}
bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int res = 0;
    while (x > res) {
        res = res * 10 + x % 10;
        x = x / 10;
    }

    if (x < res){
        res /= 10;
        if (x != res) {
            return false;
        }
    }
    return true;
}

