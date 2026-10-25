class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslandCount = 0;
      
        int directions[5] = {-1, 0, 1, 0, -1};
      
        function<int(int, int)> dfs = [&](int row, int col) -> int {
            int isClosed = (row > 0 && row < rows - 1 && col > 0 && col < cols - 1) ? 1 : 0;
          
            grid[row][col] = 1;
          
            for (int k = 0; k < 4; ++k) {
                int nextRow = row + directions[k];
                int nextCol = col + directions[k + 1];
              
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    grid[nextRow][nextCol] == 0) {
                    isClosed &= dfs(nextRow, nextCol);
                }
            }
          
            return isClosed;
        };
      
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0 && dfs(i, j)) {
                    closedIslandCount++;
                }
            }
        }
      
        return closedIslandCount;
    }
};
