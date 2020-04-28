
public class J_mianshi56-1_1 {
    public int[] singleNumbers(int[] nums) {
        int numsSize = nums.length;
        int temp = 0;
        for (int i = 0; i < numsSize; i++) temp ^= nums[i];
        int bit = 1;
        while ((bit & temp) == 0) bit <<= 1;
        int a = 0, b = 0;
        for (int i = 0; i < numsSize; i++) {
            if ((nums[i] & bit) == 0) a ^= nums[i];
            else b ^= nums[i];
        }
        return new int[]{a, b};
    }
}