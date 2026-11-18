class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
      
        vector<int> rowServerCount(numRows, 0);
        vector<int> colServerCount(numCols, 0);
      
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1) {
                    ++rowServerCount[row];
                    ++colServerCount[col];
                }
            }
        }
      
        int communicatingServers = 0;
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1 && 
                    (rowServerCount[row] > 1 || colServerCount[col] > 1)) {
                    ++communicatingServers;
                }
            }
        }
      
        return communicatingServers;
    }
};
