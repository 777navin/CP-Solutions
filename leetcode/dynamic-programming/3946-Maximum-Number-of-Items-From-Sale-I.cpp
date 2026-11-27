
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(1501, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Calculate free copies for each item type.
        vector<int> bonus(n);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int count = 0;

            for (int j = factor; j <= 1500; j += factor) {
                count += freq[j];
            }

            bonus[i] = count - 1;
        }

        // dp[b] = maximum items obtainable within budget b.
        vector<int> dp(budget + 1, 0);

        const int NEG = -1000000000;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            vector<int> prev = dp;
            vector<int> active(budget + 1, NEG);

            for (int b = 0; b <= budget; b++) {
                if (b >= price) {
                    // First purchase activates the item type.
                    active[b] = prev[b - price] + bonus[i] + 1;

                    // Additional purchases give one copy each.
                    active[b] = max(
                        active[b],
                        active[b - price] + 1
                    );
                }

                dp[b] = max(prev[b], active[b]);
            }
        }

        return dp[budget];
    }
};
