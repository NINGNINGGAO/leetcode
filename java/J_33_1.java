
public class J_33_1 {
    public int search(int[] nums, int target) {
        int numsSize = nums.length;
        if (numsSize == 0) return -1;
        if (numsSize == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int fast = 0, last = numsSize - 1, mid;
        while (fast <= last) {
            mid = (fast + last) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) last = mid - 1;
                else fast = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[numsSize - 1]) fast = mid + 1;
                else last = mid - 1;
            }
        }
        return -1;
    }
}