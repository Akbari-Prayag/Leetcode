class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int bitCount[31] = {};
      
        for (int num : nums) {
            for (int bitPos = 0; bitPos < 31; ++bitPos) {
                if ((num >> bitPos) & 1) {
                    ++bitCount[bitPos];
                }
            }
        }
      
        long long answer = 0;
        const int MOD = 1e9 + 7;
      
        while (k--) {
            int constructedNum = 0;
          
            for (int bitPos = 0; bitPos < 31; ++bitPos) {
                if (bitCount[bitPos] > 0) {
                    constructedNum |= (1 << bitPos);
                    --bitCount[bitPos];
                }
            }
          

            answer = (answer + 1LL * constructedNum * constructedNum) % MOD;
        }
      
        return answer;
    }
};
