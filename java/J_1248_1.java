import java.util.ArrayList;
import java.util.List;

class J_1248_1 {
    public int numberOfSubarrays(int[] nums, int k) {
        int numsSize = nums.length;
        List<Integer> arr = new ArrayList<>();
        arr.add(-1);
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] % 2 == 1) arr.add(i);
        }
        arr.add(numsSize);
        int ret = 0;
        if (arr.size() - 2 < k) return ret;
        for (int i = 1; i < arr.size() - k; i++) {
            ret += (arr.get(i) - arr.get(i - 1)) * (arr.get(i + k) - arr.get(i + k - 1));
        }
        return ret;
    }
}