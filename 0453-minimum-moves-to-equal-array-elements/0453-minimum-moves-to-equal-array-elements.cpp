class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minValue = INT_MAX;  
      
        for (int num : nums) {
            sum += num;
            minValue = min(minValue, num);
        }
      
        return sum - minValue * nums.size();
    }
};
