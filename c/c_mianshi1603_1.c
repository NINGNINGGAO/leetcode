/*
 * @Author: AGOGIN 
 * @Date: 2020-04-12 10:07:37 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-12 18:03:27
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* intersection(int* start1, int start1Size, int* end1, int end1Size, int* start2, int start2Size, int* end2, int end2Size, int* returnSize) {
    double *ret, k1 = 0, k2 = 0, b1 = 0, b2 = 0;
    int flag1, flag2, max_x, max_y, min_x, min_y;
    int max_x1, max_x2, max_y1, max_y2, min_x1, min_x2, min_y1, min_y2;
    ret = (double *)malloc(sizeof(double) * 2);
    if(start1[0] == start2[0] && start1[1] == start2[1]) {
        ret[0] = start1[0];
        ret[1] = start1[1];
       *returnSize = 2;
        return ret; 
    }
    if(start1[0] == end2[0] && start1[1] == end2[1]) {
        ret[0] = start1[0];
        ret[1] = start1[1];
       *returnSize = 2;
        return ret; 
    }
    if(end1[0] == end2[0] && end1[1] == end2[1]) {
        ret[0] = end1[0];
        ret[1] = end1[1];
       *returnSize = 2;
        return ret; 
    }
    if(end1[0] == start2[0] && end1[1] == start2[1]) {
        ret[0] = end1[0];
        ret[1] = end1[1];
       *returnSize = 2;
        return ret; 
    }
    max_x1 = start1[0] >= end1[0] ? start1[0] : end1[0];
    max_y1 = start1[1] >= end1[1] ? start1[1] : end1[1];
    max_x2 = start2[0] >= end2[0] ? start2[0] : end2[0];
    max_y2 = start2[1] >= end2[1] ? start2[1] : end2[1];
    min_x1 = start1[0] <= end1[0] ? start1[0] : end1[0];
    min_y1 = start1[1] <= end1[1] ? start1[1] : end1[1];
    min_x2 = start2[0] <= end2[0] ? start2[0] : end2[0];
    min_y2 = start2[1] <= end2[1] ? start2[1] : end2[1];

    if(start1[0] != end1[0]) {
        if(start1[1] == end1[1]) {
            k1 = 0;
            b1 = start1[1];
        } else {
            k1 = (start1[1] - end1[1]) * 1.0 / (start1[0] - end1[0]);
            b1 = start1[1] * 1.0 - k1 * start1[0];
        }
        flag1 = 1;
    } else {
        flag1 = 0;
    }
    if(start2[0] != end2[0]) {
        if(start2[1] == end2[1]) {
            k2 = 0;
            b2 = start2[1];
        } else {
            k2 = (start2[1] - end2[1]) * 1.0 / (start2[0] - end2[0]);
            b2 = start2[1] * 1.0 - k2 * start2[0];
        }
        flag2 = 1;
    } else {
        flag2 = 0;
    }
    if(flag1 == 1 && flag2 == 1)  {
        if(k1 == 0 && k2 != 0) {
            ret[1] = b1;
            ret[0] = (b1 - b2) / k2;
        }
        if(k1 != 0 && k2 == 0) {
            ret[1] = b2;
            ret[0] = (b2 - b1) / k1;
        }
        if(k1 == 0 && k2 == 0) {
            if(b1 != b2) {
                *returnSize = 0;
                return ret;
            } else {
                if(min_x1 <= min_x2) {
                    ret[0] = min_x1;
                    ret[1] = k1 * min_x1;
                }
                if(min_x2 <= min_x1) {
                    ret[0] = min_x2;
                    ret[1] = k1*min_x2;
                }
            }
        }
        if(k1 != 0 && k2 != 0) {
            if(k1 == k2 && b1 == b2) {
                if(min_x1 <= min_x2 && max_x2 <= max_x1) {
                    ret[0] = min_x2;
                    ret[1] = k1*min_x2+b1;
                }
                if(min_x2 <= min_x1 && max_x1 <= max_x2) {
                    ret[0] = min_x1;
                    ret[1] = k1 * min_x1 + b1;
                }
            }
            if(k1 == k2 && b1 != b2) {
                ret[1] = (k1 - k2) / (b2 - b1);
                if(k1 != 0) {
                    ret[0] = (ret[1] - b1) / k1;
                } else {
                    if(k2 != 0) {
                        ret[0] = (ret[1] - b2) / k2;
                    }
                }
            }
            if(k1 != k2 && b1 == b2) {
                ret[0] = 0;
                ret[1] = 0;
            }
            if(k1 != k2 && b1 != b2) {
                ret[0] = (b2 - b1) / (k1 - k2);
                ret[1] = k1 * ret[0] + b1;
            }
        }
    }   
    if(flag1 == 1 && flag2 == 0) {
        ret[0] = start2[0];
        ret[1] = k1 * start2[0] + b1;
    }
    if(flag1 == 0 && flag2 == 1) {
        ret[0] = start1[0];
        ret[1] = k2 * start1[0] + b2;
    }
    *returnSize = 0;
    if(ret[0] >= min_x1 && ret[0] <= max_x1 && ret[0] >= min_x2 && ret[0] <= max_x2) {    
        if(ret[1] >= min_y1 && ret[1] <= max_y1 && ret[1] >= min_y2 && ret[1] <= max_y2) {
            *returnSize = 2;
        }
    }
    if(flag1 == 0 && flag2 == 0) {
        if(start1[0] == start2[0]) {
            if(min_y1 > max_y2 || min_y2 > max_y1) {
                *returnSize = 0;
            }
            if(max_y2 >= min_y1 && max_y1 >= max_y2) {
                *returnSize = 2;
                ret[0] = start1[0];
                ret[1] = min_y1;
            }
            if(max_y1 >= min_y2 && max_y2 >= max_y1) {
                *returnSize = 2;
                ret[0] = start1[0];
                ret[1] = min_y2;
            }
        } else {
            *returnSize = 0;
        }
    }
    return ret;
}


int main() {

}