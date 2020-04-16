import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class J_56_1 {
    public int[][] merge(int[][] intervals) {
    	if (intervals.length < 2) return intervals;
    	Arrays.sort(intervals, (x, y) -> x[0] - y[0]);
    	List<int[]> ret = new ArrayList<int[]>();
    	ret.add(intervals[0]);
    	for (int i = 1; i < intervals.length; i++) {
    		if (ret.get(ret.size() - 1)[1] >= intervals[i][0]) {
    			ret.get(ret.size() - 1)[1] = Math.max(ret.get(ret.size() - 1)[1], intervals[i][1]);
    		}
    		else ret.add(intervals[i]);
    	}
    	return ret.toArray(new int[ret.size()][2]);
    }
}
