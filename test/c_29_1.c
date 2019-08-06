#include <stdio.h>
#include <limits.h>



int divide(int dividend, int divisor){
    if (dividend == 0) return 0;
    if (dividend == INT_MIN && divisor == INT_MIN) return 1;
    int flag = (dividend ^ divisor) > 0 ? 0 : 1;
    if (dividend == INT_MIN){
        dividend = INT_MAX;
    }
    if (divisor == INT_MIN) {
        divisor = INT_MAX;
    }
    int i = 0;
    int ret[32], temp[32];
    ret[0] = 1;
    temp[0] = divisor;

    int mid = 0;
    while (dividend > temp[i]) {
        temp[i + 1] = temp[i] + temp[i];
        ret[i + 1] = ret[i] + ret[i]; 
        mid = 1;
    }
    if (mid == 1) i--;
    if (dividend == temp[i]) {
        if (flag == 1) return -ret[i];
        return ret[i];
    }
    int res = ret[i];
    while (i > 0)

}

main() {
    int dividend = INT_MIN + 1;
    int divisor = INT_MIN + 1;
    printf("%d\n", divide(dividend, divisor));
}