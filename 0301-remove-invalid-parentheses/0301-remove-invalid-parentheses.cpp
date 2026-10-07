class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;  
        int leftToRemove = 0;          
        int rightToRemove = 0;         
        int n = s.size();
      
        
        for (char& ch : s) {
            if (ch == '(') {
                leftToRemove++;
            } else if (ch == ')') {
                if (leftToRemove > 0) {
                    leftToRemove--;  
                } else {
                    rightToRemove++;  
                }
            }
        }
      
        
        function<void(int, int, int, int, int, string)> dfs;
        dfs = [&](int index, int leftRem, int rightRem, int leftCount, int rightCount, string current) {
           
            if (index == n) {
                
                if (leftRem == 0 && rightRem == 0) {
                    result.insert(current);
                }
                return;
            }
          
            
            if (n - index < leftRem + rightRem || leftCount < rightCount) {
                return;
            }
          
            if (s[index] == '(' && leftRem > 0) {
                dfs(index + 1, leftRem - 1, rightRem, leftCount, rightCount, current);
            }
          
            if (s[index] == ')' && rightRem > 0) {
                dfs(index + 1, leftRem, rightRem - 1, leftCount, rightCount, current);
            }
          
            int addLeft = (s[index] == '(') ? 1 : 0;
            int addRight = (s[index] == ')') ? 1 : 0;
            dfs(index + 1, leftRem, rightRem, leftCount + addLeft, rightCount + addRight, current + s[index]);
        };
      
        dfs(0, leftToRemove, rightToRemove, 0, 0, "");
      
        return vector<string>(result.begin(), result.end());
    }
};
