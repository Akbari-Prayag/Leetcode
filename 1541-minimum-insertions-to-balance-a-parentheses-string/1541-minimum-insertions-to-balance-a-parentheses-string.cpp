class Solution {
public:
    int minInsertions(string s) {
        int insertionsNeeded = 0;  
        int openParentheses = 0;    
        int n = s.size();
      
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++openParentheses;
            } else {
              
                if (i < n - 1 && s[i + 1] == ')') {
                    ++i;
                } else {
                    ++insertionsNeeded;
                }
              
                if (openParentheses == 0) {
                    ++insertionsNeeded;
                } else {
                    --openParentheses;
                }
            }
        }
      
        insertionsNeeded += openParentheses * 2;
      
        return insertionsNeeded;
    }
};
