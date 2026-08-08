class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one number
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // Consider subarrays of increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                // Take left number
                int takeLeft = nums[i] - dp[i + 1][j];

                // Take right number
                int takeRight = nums[j] - dp[i][j - 1];

                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        // Player 1 wins or ties
        return dp[0][n - 1] >= 0;
    }
};