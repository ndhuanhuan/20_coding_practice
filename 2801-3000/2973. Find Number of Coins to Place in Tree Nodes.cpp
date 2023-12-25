// https://leetcode.cn/problems/find-number-of-coins-to-place-in-tree-nodes/solutions/2577675/tan-xin-pythonjavacgo-by-endlesscheng-j58c/
class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost) {
        int n = cost.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<long long> ans(n, 1);
        function<vector<int>(int, int)> dfs = [&](int x, int fa) -> vector<int> {
            vector<int> a = {cost[x]};
            for (int y: g[x]) {
                if (y != fa) {
                    auto res = dfs(y, x);
                    a.insert(a.end(), res.begin(), res.end());
                }
            }
            sort(a.begin(), a.end());
            int m = a.size();
            if (m >= 3) {
                //                 如果只考虑正数，显然最大的三个数的乘积是最大的。
                // 如果把负数也考虑进来，那么最小的两个负数乘最大的正数也可能是最大值。
                ans[x] = max({(long long) a[m - 3] * a[m - 2] * a[m - 1], (long long) a[0] * a[1] * a[m - 1], 0LL});
            }
            if (m > 5) {
                a = {a[0], a[1], a[m - 3], a[m - 2], a[m - 1]};
            }
            return a;
        };
        dfs(0, -1);
        return ans;
    }
};

