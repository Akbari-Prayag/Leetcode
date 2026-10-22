class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        if (n == 2) {
            return (nums[0] == 0) ? 0 : 1;
        }

        int p0 = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p0 = i;
                break;
            }
        }

        bool asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(p0 + i) % n] != i) {
                asc = false;
                break;
            }
        }

        if (asc) {
            int op1 = p0;
            int op2 = (n - p0) % n + 2;
            return min(op1, op2);
        }

        bool desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(p0 - i + n) % n] != i) {
                desc = false;
                break;
            }
        }

        if (desc) {
            int op1 = (n - 1 - p0) + 1;
            int op2 = (p0 + 1) % n + 1;
            return min(op1, op2);
        }

        return -1;
    }
};