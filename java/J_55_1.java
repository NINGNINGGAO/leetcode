
public class J_55_1 {
    public boolean canJump(int[] nums) {
    	int numsSize = nums.length;
    	int rightMost = 0;
    	for (int i = 0; i < numsSize; i++) {
    		if (i <= rightMost) {
    			rightMost = Math.max(rightMost, nums[i] + i);
    			if (rightMost >= numsSize - 1) return true;
    		}
    	}
    	return false;
    }
}
