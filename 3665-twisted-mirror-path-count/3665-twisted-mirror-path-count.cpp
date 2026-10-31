#include <vector>

using namespace std;

class Solution {
    int m, n;
    const int MOD = 1e9 + 7;
    
    // Memoization tables
    // dp[r][c]: number of valid paths from empty cell (r, c) to (m - 1, n - 1)
    vector<vector<int>> dp;
    
    // next_land[r][c][dir]: stores the landing coordinate {r', c'} after all reflections
    // dir: 0 = RIGHT, 1 = DOWN
    vector<vector<vector<pair<int, int>>>> next_land;

    // Resolves reflection chains deterministically
    pair<int, int> getLanding(int r, int c, int dir, const vector<vector<int>>& grid) {
        if (r >= m || c >= n) return {-1, -1}; // Out of bounds
        
        if (next_land[r][c][dir].first != -2) {
            return next_land[r][c][dir];
        }
        
        // If it reaches destination directly or lands on an empty cell
        if (r == m - 1 && c == n - 1) {
            return next_land[r][c][dir] = {r, c};
        }
        
        if (grid[r][c] == 0) {
            return next_land[r][c][dir] = {r, c};
        }
        
        // Grid cell is a mirror: reflect
        if (dir == 0) { // Moving Right -> turned Down to (r + 1, c)
            return next_land[r][c][dir] = getLanding(r + 1, c, 1, grid);
        } else {        // Moving Down -> turned Right to (r, c + 1)
            return next_land[r][c][dir] = getLanding(r, c + 1, 0, grid);
        }
    }

    int countPaths(int r, int c, const vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1) return 1;
        if (dp[r][c] != -1) return dp[r][c];
        
        long long paths = 0;
        
        // Option 1: Move Right
        auto [r_right, c_right] = getLanding(r, c + 1, 0, grid);
        if (r_right != -1) {
            paths = (paths + countPaths(r_right, c_right, grid)) % MOD;
        }
        
        // Option 2: Move Down
        auto [r_down, c_down] = getLanding(r + 1, c, 1, grid);
        if (r_down != -1) {
            paths = (paths + countPaths(r_down, c_down, grid)) % MOD;
        }
        
        return dp[r][c] = paths;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        dp.assign(m, vector<int>(n, -1));
        next_land.assign(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-2, -2})));
        
        return countPaths(0, 0, grid);
    }
};