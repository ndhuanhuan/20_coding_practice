// https://leetcode.cn/problems/count-k-reducible-numbers-less-than-n/solutions/
class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        const int MOD = 1'000'000'007;
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto dfs = [&](auto& dfs, int i, int left1, bool is_limit) -> int {
            if (i == n) {
                return !is_limit && left1 == 0;
            }
            if (!is_limit && memo[i][left1] != -1) {
                return memo[i][left1];
            }
            int up = is_limit ? s[i] - '0' : 1;
            int res = 0;
            for (int d = 0; d <= min(up, left1); d++) {
                res = (res + dfs(dfs, i + 1, left1 - d, is_limit && d == up)) % MOD;
            }
            if (!is_limit) {
                memo[i][left1] = res;
            }
            return res;
        };

        long long ans = 0;
        vector<int> f(n);
        for (int i = 1; i < n; i++) {
            f[i] = f[__builtin_popcount(i)] + 1;
            if (f[i] <= k) {
                // 计算有多少个二进制数恰好有 i 个 1
                ans += dfs(dfs, 0, i, true);
            }
        }
        return ans % MOD;
    }
};
