// https://leetcode.cn/problems/maximize-sum-of-weights-after-edge-removals/solutions/2998845/shu-xing-dp-tan-xin-pythonjavacgo-by-end-i3g3/
class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        vector<vector<pair<int, int>>> g(edges.size() + 1);
        for (auto& e : edges) {
            int x = e[0], y = e[1], wt = e[2];
            g[x].emplace_back(y, wt);
            g[y].emplace_back(x, wt);
        }

        auto dfs = [&](auto& dfs, int x, int fa) -> pair<long long, long long> {
            long long not_choose = 0;
            vector<long long> inc;
            for (auto& [y, wt] : g[x]) {
                if (y == fa) {
                    continue;
                }
                auto [nc, c] = dfs(dfs, y, x);
                not_choose += nc; // 先都不选
                long long d = c + wt - nc;
                if (d > 0) {
                    inc.push_back(d);
                }
            }

            // 再选增量最大的 k 个或者 k-1 个
            ranges::sort(inc, greater()); // 从大到小排序
            for (int i = 0; i < min((int) inc.size(), k - 1); i++) {
                not_choose += inc[i];
            }
            long long choose = not_choose;
            if (inc.size() >= k) {
                not_choose += inc[k - 1];
            }
            return {not_choose, choose};
        };
        return dfs(dfs, 0, -1).first; // not_choose >= choose
    }
};
