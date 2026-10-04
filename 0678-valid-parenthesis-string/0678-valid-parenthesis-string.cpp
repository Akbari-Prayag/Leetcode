class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
      
       
        vector<vector<bool>> dp(n, vector<bool>(n, false));
      
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = (s[i] == '*');
        }
      
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                char leftChar = s[i];
                char rightChar = s[j];
              
               
                bool canFormPair = (leftChar == '(' || leftChar == '*') && 
                                   (rightChar == ')' || rightChar == '*') &&
                                   (i + 1 == j || dp[i + 1][j - 1]);
              
                dp[i][j] = canFormPair;
              
                
                for (int k = i; k < j && !dp[i][j]; ++k) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
      
       
        return dp[0][n - 1];
    }
};
