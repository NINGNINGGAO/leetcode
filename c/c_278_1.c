/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 11:19:44
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 20:27:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int p = 1, q = n;
    int mid = p;
    if (isBadVersion(p) == true) return mid;
    while (p < q) {
        if (q - p == 1) return q;
        mid = p + (q - p) / 2;
        if (isBadVersion(mid) == false) p = mid;
        else q = mid;
    }
    return mid;
}

int main() {
    int res = firstBadVersion(5);
    return 0;
}