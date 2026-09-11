class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        int n = digits.size();
      
        for (int i = 0; i < n; ++i) {
            if (digits[i] % 2 == 1) {
                continue;
            }
          
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
              
                for (int k = 0; k < n; ++k) {
                    if (digits[k] == 0 || k == i || k == j) {
                        continue;
                    }
                  
                    int number = digits[k] * 100 + digits[j] * 10 + digits[i];
                    uniqueNumbers.insert(number);
                }
            }
        }
      
        return uniqueNumbers.size();
    }
};
