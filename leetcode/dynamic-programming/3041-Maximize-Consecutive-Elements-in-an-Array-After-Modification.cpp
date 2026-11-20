#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 1;

        for (int x : nums) {
            // 1. Use x as (x + 1), extending a chain ending at x
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            ans = max(ans, dp[x + 1]);

            // 2. Keep x as x, extending a chain ending at (x - 1)
            dp[x] = max(dp[x], dp[x - 1] + 1);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};