import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class J_46_1 {
    private void backTrack(List<List<Integer>> ret, int[] nums, List<Integer> temp, boolean[] flag) {
        int numsSize = nums.length;
        if (temp.size() == numsSize) {
            ret.add(new LinkedList(temp));
            return;
        }
        for (int i = 0; i < numsSize; i++) {
            if (flag[i] == false) {
                flag[i] = true;
                temp.add(nums[i]);
                backTrack(ret, nums, temp, flag);
                temp.remove(temp.size() - 1);
                flag[i] = false;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer> > ret = new ArrayList<>();
        boolean[] flag = new boolean[nums.length];
        List<Integer> temp = new ArrayList<>();
        backTrack(ret, nums, temp, flag);
        return ret;
    }
}