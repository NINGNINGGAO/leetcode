/*
 * @Author: AGOGIN
 * @Date: 2019-11-12 20:27:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-12 21:05:57
 */
class J_7_1 {
    public int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int temp = x % 10;
            x /= 10;
            if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && temp > 7)) return 0;
            if (res < Integer.MIN_VALUE / 10 || (res == Integer.MIN_VALUE / 10 && temp < -8)) return 0;
            res = res * 10 + temp;
        }
        return res;
    }
}