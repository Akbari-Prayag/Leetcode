class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> targetFreq(128, 0);
        vector<int> windowFreq(128, 0);
      
        for (char c : t) {
            targetFreq[c]++;
        }

        int sLen = s.length();
        int tLen = t.length();
      
        int minStart = -1; 
        int minLength = sLen + 1;  
        int validCharCount = 0;  

        int left = 0;
        for (int right = 0; right < sLen; right++) {
            char rightChar = s[right];
            windowFreq[rightChar]++;
          
            if (windowFreq[rightChar] <= targetFreq[rightChar]) {
                validCharCount++;
            }

            while (validCharCount == tLen) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
              
                if (windowFreq[leftChar] <= targetFreq[leftChar]) {
                    validCharCount--;
                }
              
                windowFreq[leftChar]--;
                left++;
            }
        }

        return minStart == -1 ? "" : s.substr(minStart, minLength);
    }
};