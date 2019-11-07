/*
 * @Author: AGOGIN
 * @Date: 2019-11-07 11:20:09
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-07 17:32:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void quickSort(int* nums,int first,int end){
    int temp,l,r;
    if(first>=end)return;
    temp=nums[first];
    l=first;r=end;
    while(l<r){
        while(l<r && nums[r]>=temp)r--;
        if(l<r)nums[l]=nums[r];
        while(l<r && nums[l]<=temp)l++;
        if(l<r)nums[r]=nums[l];
    }
    nums[l]=temp;
    quickSort(nums,first,l-1);
    quickSort(nums,l+1,end);
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    if (pointsSize < 2) return 0;
    int i, j, k, l, m, n, count = 0;
    int lineSize = pointsSize-1;
    int *lines = malloc(sizeof(int)*lineSize);
    for (i = 0; i < pointsSize; ++i) {
        k = 0;
        for (j = 0; j < pointsSize; ++j) {
            if (i == j) continue;
            lines[k++] = pow(points[i][0]-points[j][0], 2)+pow(points[i][1]-points[j][1], 2);
        }
        quickSort(lines, 0, lineSize-1);
        m = lines[0];
        n = 1;
        for (l = 1; l < lineSize; ++l) {
            if (lines[l] != m) {
                if (n >= 2) count += n*(n-1);
                m = lines[l];
                n = 1;
            }else{
                ++n;
            }
        }
        if (n >= 2) count += n*(n-1);
    }

    free(lines);
    return count;
}

int main() {
    int** points = malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        points[i] = malloc(sizeof(int) * 2);
        points[i][0] = i;
        points[i][1] = 0;
    }
    int temp;
    int res = numberOfBoomerangs(points, 3, &temp);
    return 0;
}