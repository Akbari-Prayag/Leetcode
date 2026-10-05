class Solution {
public:
    int scoreOfParentheses(string s) {
        int totalScore = 0;  
        int depth = 0;       
      
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
            } else {  
                --depth;
              
                if (s[i - 1] == '(') {
                    totalScore += (1 << depth);  
                }
            }
        }
      
        return totalScore;
    }
};
