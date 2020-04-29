/*
 * @Author: AGOGIN 
 * @Date: 2020-04-29 21:59:22 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-29 22:14:03
 */
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int searchMountain(int target, MountainArray &mountainArr, int l, int r, int key(int)) {
        target = key(target);
        while (l <= r) {
            int mid = (l + r) / 2;
            int midValue = key(mountainArr.get(mid));
            if (midValue == target) return mid;
            else if (midValue > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0;
        int r = mountainArr.length() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) l = mid + 1;
            else r = mid;
        }
        int peak = l;
        int lIndex = searchMountain(target, mountainArr, 0, peak, [](int x) -> int{return x;});
        if (lIndex >= 0) return lIndex;
        else {
            int rIndex = searchMountain(target, mountainArr, peak + 1, mountainArr.length() - 1, [](int x) -> int{return -x;});
            if (rIndex >= 0) return rIndex;
            else return -1;
        }
    }
};