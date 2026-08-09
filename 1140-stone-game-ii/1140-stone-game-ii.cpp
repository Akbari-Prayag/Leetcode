class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int numPiles = piles.size();
      
    
        vector<int> prefixSum(numPiles + 1, 0);
        for (int i = 0; i < numPiles; ++i) {
            prefixSum[i + 1] = prefixSum[i] + piles[i];
        }
      
        vector<vector<int>> dp(numPiles, vector<int>(numPiles + 1, 0));
      
    
        function<int(int, int)> dfs = [&](int index, int M) -> int {
         
            if (2 * M >= numPiles - index) {
                return prefixSum[numPiles] - prefixSum[index];
            }

            if (dp[index][M] != 0) {
                return dp[index][M];
            }
          
            int maxStones = 0;
          

            for (int X = 1; X <= 2 * M; ++X) {

                int stonesIfTakeX = prefixSum[numPiles] - prefixSum[index] - 
                                    dfs(index + X, max(X, M));
                maxStones = max(maxStones, stonesIfTakeX);
            }

            dp[index][M] = maxStones;
            return maxStones;
        };
      

        return dfs(0, 1);
    }
};
