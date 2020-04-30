/*
 * @Author: AGOGIN 
 * @Date: 2020-04-30 13:09:56 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-30 13:21:14
 */

class Solution {
private:
    int bitSquareSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        int slow = n, fast = n;
        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);
        return fast == 1;
    }
};