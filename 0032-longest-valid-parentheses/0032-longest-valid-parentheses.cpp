class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
      
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
      
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    dp[i] = dp[i - 2] + 2;
                } 
                else {
                    int matchIndex = i - dp[i - 1] - 1;
                  
                    if (matchIndex > 0 && s[matchIndex - 1] == '(') {
                        dp[i] = dp[i - 1] + 2 + dp[matchIndex - 1];
                    }
                }
            }
        }
      
        return *max_element(dp, dp + n + 1);
    }
};
