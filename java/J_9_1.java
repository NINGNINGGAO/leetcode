/*
 * @Author: AGOGIN
 * @Date: 2019-11-12 21:08:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-12 22:03:10
 */
class J_9_1 {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
}