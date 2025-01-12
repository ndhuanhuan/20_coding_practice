// https://leetcode.cn/problems/minimize-the-maximum-edge-weight-of-graph/solutions/3045060/liang-chong-fang-fa-er-fen-da-an-dijkstr-eb7d/

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int) {
        if (edges.size() < n - 1) {
            return -1;
        }

        vector<vector<pair<int, int>>> g(n);
        int max_w = 0;
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[y].emplace_back(x, w);
            max_w = max(max_w, w);
        }

        vector<int> vis(n);
        auto check = [&](int upper) -> bool {
            int left = n;
            auto dfs = [&](this auto&& dfs, int x) -> void {
                vis[x] = upper; // 避免每次二分重新创建 vis 数组
                left--;
                for (auto& [y, w] : g[x]) {
                    if (w <= upper && vis[y] != upper) {
                        dfs(y);
                    }
                }
            };
            dfs(0);
            return left == 0;
        };

        int left = 0, right = max_w + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right > max_w ? -1 : right;
    }
};
