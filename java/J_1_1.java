import java.util.HashMap;
import java.util.Map;

/*
 * @Author: AGOGIN
 * @Date: 2019-11-06 22:17:42
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-06 22:27:01
 */
class J_1_1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}