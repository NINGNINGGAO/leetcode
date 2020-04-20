
public class J_200_1 {
	static void dfs(char[][] grid, int row, int col) {
		int n = grid.length;
		int m = grid[0].length;
		if (row < 0 || col < 0 || row > n - 1 || col > m - 1 || grid[row][col] == '0') return;
		grid[row][col] = '0';
		dfs(grid, row - 1, col);
		dfs(grid, row, col - 1);
		dfs(grid, row + 1, col);
		dfs(grid, row, col + 1);
	}
    public static int numIslands(char[][] grid) {
    	int n = grid.length;
    	if (n == 0) return 0;
    	int m = grid[0].length;
    	int ret = 0;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			if (grid[i][j] == '1') {
    				ret++;
    				dfs(grid, i, j);
    			}
    		}
    	}
    	return ret;
    }
    public static void main(String[] args) {
    	char[][] grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    	int ret = numIslands(grid);
    	System.out.println(ret);
    }
}
