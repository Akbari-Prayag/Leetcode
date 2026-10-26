class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        vector<int> directions = {-1, 0, 1, 0, -1};

        auto depthFirstSearch = [&](this auto&& depthFirstSearch, int row, int col) -> long long {
            long long islandSum = grid[row][col];
          
            grid[row][col] = 0;
          
            for (int dir = 0; dir < 4; ++dir) {
                int nextRow = row + directions[dir];
                int nextCol = col + directions[dir + 1];
              
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    grid[nextRow][nextCol] != 0) {
                    islandSum += depthFirstSearch(nextRow, nextCol);
                }
            }
          
            return islandSum;
        };

        int islandCount = 0;
      
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    long long currentIslandSum = depthFirstSearch(i, j);
                  
                    if (currentIslandSum % k == 0) {
                        ++islandCount;
                    }
                }
            }
        }
      
        return islandCount;
    }
};
