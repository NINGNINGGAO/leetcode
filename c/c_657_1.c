/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 16:49:35
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 16:53:17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool judgeCircle(char * moves){
    int sLen = strlen(moves);
    if (sLen == 0) return true;
    int* nums = malloc(sizeof(int) * 4);
    memset(nums, 0, sizeof(int) * 4);
    for (int i = 0; i < sLen; i++) {
        if (moves[i] == 'R') nums[0]++;
        else if (moves[i] == 'L') nums[1]++;
        else if (moves[i] == 'U') nums[2]++;
        else if (moves[i] == 'D') nums[3]++;
    }
    if (nums[0] == nums[1] && nums[2] == nums[3]) return true;
    else return false;
}

int main() {

    return 0;
}