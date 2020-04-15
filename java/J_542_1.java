
public class J_542_1 {
    public int[][] updateMatrix(int[][] matrix) {
    	int row = matrix.length, col = matrix[0].length;
    	int[][] ret = new int[row][col];
    	for (int i = 0; i < row; i++) {
    		for (int j = 0; j < col; j++) {
    			ret[i][j] = matrix[i][j] == 0 ? 0 : Integer.MAX_VALUE / 2;
    		}
    	}
    	for (int i = 0; i < row; i++) {
    		for (int j = 0; j < col; j++) {
    			if (i != 0) ret[i][j] = Math.min(ret[i][j], ret[i - 1][j] + 1);
    			if (j != 0) ret[i][j] = Math.min(ret[i][j], ret[i][j - 1] + 1);
    		}
    	}
    	for (int i = row - 1; i >= 0; i--) {
    		for (int j = col - 1; j >= 0; j--) {
    			if (i != row - 1) ret[i][j] = Math.min(ret[i][j], ret[i + 1][j] + 1);
    			if (j != col - 1) ret[i][j] = Math.min(ret[i][j], ret[i][j + 1] + 1);
    		}
    	}
    	return ret;
    }
}
