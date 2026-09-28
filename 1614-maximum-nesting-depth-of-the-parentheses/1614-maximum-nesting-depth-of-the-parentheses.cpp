class Solution {
public:
    int maxDepth(string s) {
        int maxNestingDepth = 0;  
        int currentDepth = 0;      
      
        for (char& ch : s) {
            if (ch == '(') {
                currentDepth++;
                maxNestingDepth = max(maxNestingDepth, currentDepth);
            } else if (ch == ')') {
                currentDepth--;
            }
        }
      
        return maxNestingDepth;
    }
};
