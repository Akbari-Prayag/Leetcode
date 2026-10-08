class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int openCount = 0;  
      
        for (char& ch : s) {
            if (ch == '(') {
                openCount++;
                if (openCount > 1) {
                    result.push_back(ch);
                }
            } else {  
                openCount--;
                if (openCount > 0) {
                    result.push_back(ch);
                }
            }
        }
      
        return result;
    }
};
