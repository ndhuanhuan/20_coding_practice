// https://leetcode.cn/problems/minimum-cost-to-split-an-array/solution/by-endlesscheng-05s0/
class Solution {
public:
    int minCost(vector<int> &nums, int k) {
        int n = nums.size(), f[n + 1];
        f[0] = 0;
        int8_t state[n];
        for (int i = 0; i < n; ++i) {
            memset(state, 0, sizeof(state));
            int unique = 0, mn = INT_MAX;
            for (int j = i; j >= 0; --j) {
                int x = nums[j];
                if (state[x] == 0) state[x] = 1, ++unique; // 首次出现
                else if (state[x] == 1) state[x] = 2, --unique; // 不再唯一
                mn = min(mn, f[j] - unique);
            }
            f[i + 1] = k + mn;
        }
        return f[n] + n;
    }
};
