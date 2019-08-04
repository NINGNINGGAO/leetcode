#include <stdio.h>
#include <limits.h>


double myPow(double x, int n){
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    int flag = 0;
    if (n == INT_MIN) {
        n = INT_MAX;
        x = 1 / x;
        flag = 1;
    }
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    double nums[32];
    int m = 0;
    while (n != 0) {
        nums[m] = n % 2;
        n >>=1;
        m++;
    }
    double temp = x;
    double ret = 1;
    double mid = 1;
    for (int i = 0; i < m; i++) {
        mid = nums[i] ? temp : 1;
        ret *= mid;
        temp = temp * temp;
    }
    if (flag == 1) {
        return ret * x;
    } else {
    return ret;
    }
}


main() {
    double x = 2;
    int n = -2147483648;
    printf("%f\n", myPow(x, n));
}