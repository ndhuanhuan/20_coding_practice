class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].emplace_back(y, 1);
            g[y].emplace_back(x, -1); // 从 y 到 x 需要反向
        }

        vector<int> ans(n, 0);
        function<void(int, int)> dfs = [&](int x, int fa) {
            for (auto &[y, dir]: g[x]) {
                if (y != fa) {
                    ans[0] += dir < 0;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        function<void(int, int)> reroot = [&](int x, int fa) {
            for (auto &[y, dir]: g[x]) {
                if (y != fa) {
                    ans[y] = ans[x] + dir; // dir 就是从 x 换到 y 的「变化量」
                    reroot(y, x);
                }
            }
        };
        reroot(0, -1);
        return ans;
    }
};
