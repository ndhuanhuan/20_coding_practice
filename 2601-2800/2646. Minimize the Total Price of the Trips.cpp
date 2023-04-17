// https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/solution/lei-si-da-jia-jie-she-iii-pythonjavacgo-4k3wq/
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }

        int cnt[n]; memset(cnt, 0, sizeof(cnt));
        for (auto &t: trips) {
            int end = t[1];
            function<bool(int, int)> dfs = [&](int x, int fa) -> bool {
                if (x == end) { // 到达终点（注意树只有唯一的一条简单路径）
                    ++cnt[x]; // 统计从 start 到 end 的路径上的点经过了多少次
                    return true; // 找到终点
                }
                for (int y: g[x])
                    if (y != fa && dfs(y, x)) {
                        ++cnt[x]; // 统计从 start 到 end 的路径上的点经过了多少次
                        return true; // 找到终点
                    }
                return false; // 未找到终点
            };
            dfs(t[0], -1);
        }

        // 类似 337. 打家劫舍 III https://leetcode.cn/problems/house-robber-iii/
        function<pair<int, int>(int, int)> dfs = [&](int x, int fa) -> pair<int, int> {
            int not_halve = price[x] * cnt[x]; // x 不变
            int halve = not_halve / 2; // x 减半
            for (int y: g[x])
                if (y != fa) {
                    auto [nh, h] = dfs(y, x); // 计算 y 不变/减半的最小价值总和
                    not_halve += min(nh, h); // x 不变，那么 y 可以不变，可以减半，取这两种情况的最小值
                    halve += nh; // x 减半，那么 y 只能不变
                }
            return {not_halve, halve};
        };
        auto [nh, h] = dfs(0, -1);
        return min(nh, h);
    }
};
