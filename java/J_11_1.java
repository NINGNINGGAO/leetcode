
public class J_11_1 {
    public int maxArea(int[] height) {
    	int ret = 0;
    	int fast = 0;
    	int last = height.length - 1;
    	while (fast < last) {
    		int temp = Math.min(height[fast], height[last]) * (last - fast);
    		ret = Math.max(ret, temp);
    		if (height[fast] < height[last]) fast++;
    		else last--;
    	}
    	return ret;
    }
}
