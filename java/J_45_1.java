public class J_45_1 {
    public int jump(int[] nums) {
        int numsSize = nums.length;
        int ret = 0;
        int bound = 0;
        int maxPosition = 0;
        for (int i = 0; i < numsSize - 1; i++) {
            maxPosition = Math.max(maxPosition, i + nums[i]);
            if (i == bound) {
                bound = maxPosition;
                ret++;
            }
        }
        return ret;
    }
}