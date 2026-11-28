
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        // Count frequency of each factor
        for (auto &item : items) {
            freq[item[0]]++;
        }

        vector<int> freeCount(n + 1, 0);

        // Sieve: count all divisible items
        for (int d = 1; d <= n; d++) {
            for (int j = d; j <= n; j += d) {
                freeCount[d] += freq[j];
            }

            // Exclude only the current item
            freeCount[d]--;
        }

        int minPrice = INT_MAX;

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        vector<pair<int, int>> v;

        for (auto &item : items) {
            v.push_back({
                item[1],
                freeCount[item[0]]
            });
        }

        // Cheapest double-value purchases first
        sort(v.begin(), v.end());

        long long remaining = budget;
        long long ans = 0;

        for (auto &[price, cnt] : v) {

            // Two copies at this price are not
            // better than two cheapest single copies
            if (price >= 2LL * minPrice)
                break;

            long long take = min(
                (long long)cnt,
                remaining / price
            );

            ans += 2LL * take;
            remaining -= take * price;
        }

        // Use remaining budget for cheapest items
        ans += remaining / minPrice;

        return (int)ans;
    }
};
