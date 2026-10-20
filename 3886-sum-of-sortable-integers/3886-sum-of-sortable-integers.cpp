class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n && valid; start += k) {
                int descents = 0;

                for (int i = 0; i < k; i++) {
                    int curr = start + i;
                    int next = start + (i + 1) % k;

                    if (nums[curr] > nums[next]) {
                        descents++;
                    }
                }

                if (descents > 1) {
                    valid = false;
                }
            }

            if (valid) {
                // Check if the rotated blocks can form a sorted array.
                for (int start = k; start < n && valid; start += k) {
                    int prevMax = *max_element(
                        nums.begin() + start - k,
                        nums.begin() + start
                    );

                    int nextMin = *min_element(
                        nums.begin() + start,
                        nums.begin() + start + k
                    );

                    if (prevMax > nextMin) {
                        valid = false;
                    }
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};