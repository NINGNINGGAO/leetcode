/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

class J_1095_1 {
    private int searchMountain(int target, MountainArray mountainArr, int l, int r, Function<Integer, Integer> f) {
        int mid, midValue;
        target = f.apply(target);
        while (l <= r) {
            mid = (l + r) / 2;
            midValue = f.apply(mountainArr.get(mid));
            if (midValue == target) return mid;
            else if (midValue > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int arrSize = mountainArr.length();
        int l = 0, r = arrSize - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) l = mid + 1;
            else r = mid;
        }
        int peak = l;
        int lIndex = searchMountain(target, mountainArr, 0, peak, x -> x);
        if (lIndex >= 0) return lIndex;
        else {
            int rIndex = searchMountain(target, mountainArr, peak + 1, arrSize - 1, x -> -x);
            if (rIndex >= 0) return rIndex;
            else return -1;
        }
    }
}