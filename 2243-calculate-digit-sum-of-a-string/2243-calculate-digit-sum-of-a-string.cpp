class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string nextString;
            int stringLength = s.size();
          
            for (int startIndex = 0; startIndex < stringLength; startIndex += k) {
                int groupSum = 0;
              
                for (int currentIndex = startIndex; currentIndex < min(startIndex + k, stringLength); ++currentIndex) {
                    groupSum += s[currentIndex] - '0';
                }
              
                nextString += to_string(groupSum);
            }
          
            s = nextString;
        }
      
        return s;
    }
};
