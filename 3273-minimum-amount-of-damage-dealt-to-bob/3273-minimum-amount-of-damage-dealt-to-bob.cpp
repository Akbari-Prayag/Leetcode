class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<long long, long long>> enemies(n);

        for (int i = 0; i < n; i++) {
            long long hits = (health[i] + power - 1LL) / power;
            enemies[i] = {damage[i], hits};
        }

        sort(enemies.begin(), enemies.end(), [](const auto& a, const auto& b) {
            return a.first * b.second > b.first * a.second;
        });

        long long totalDamage = 0;
        long long remainingDamage = 0;

        for (int i = 0; i < n; i++) {
            remainingDamage += enemies[i].first;
        }

        for (int i = 0; i < n; i++) {
            totalDamage += remainingDamage * enemies[i].second;
            remainingDamage -= enemies[i].first;
        }

        return totalDamage;
    }
};