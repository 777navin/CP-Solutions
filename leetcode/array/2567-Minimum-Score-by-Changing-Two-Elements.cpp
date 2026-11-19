#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int opt1 = nums[n - 3] - nums[0];     // Change 2 largest elements
        int opt2 = nums[n - 1] - nums[2];     // Change 2 smallest elements
        int opt3 = nums[n - 2] - nums[1];     // Change 1 smallest and 1 largest

        return min({opt1, opt2, opt3});
    }
};