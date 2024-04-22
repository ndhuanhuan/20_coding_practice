// https://leetcode.cn/problems/find-edges-in-shortest-paths/solutions/2749274/dijkstra-zui-duan-lu-dfsbfs-zhao-bian-py-yf48/
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w, i);
            g[y].emplace_back(x, w, i);
        }

        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x]) {
                continue;
            }
            for (auto [y, w, _] : g[x]) {
                int new_dis = dx + w;
                if (new_dis < dis[y]) {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }

        vector<bool> ans(edges.size());
        // 图不连通
        if (dis[n - 1] == LLONG_MAX) {
            return ans;
        }

        // 从终点出发 DFS
        vector<int> vis(n);
        function<void(int)> dfs = [&](int y) {
            vis[y] = true;
            for (auto [x, w, i] : g[y]) {
                if (dis[x] + w != dis[y]) {
                    continue;
                }
                ans[i] = true;
                if (!vis[x]) {
                    dfs(x);
                }
            }
        };
        dfs(n - 1);
        return ans;
    }
};

