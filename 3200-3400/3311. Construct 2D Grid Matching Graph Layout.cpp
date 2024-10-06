// https://leetcode.cn/problems/construct-2d-grid-matching-graph-layout/solutions/2940537/fen-lei-tao-lun-zhu-xing-gou-zao-by-endl-v3x0/
class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // 每种度数选一个点
        int deg_to_node[5]{-1, -1, -1, -1, -1};
        for (int x = 0; x < n; x++) {
            deg_to_node[g[x].size()] = x;
        }

        vector<int> row;
        if (deg_to_node[1] != -1) {
            // 答案只有一列
            row = {deg_to_node[1]};
        } else if (deg_to_node[4] == -1) {
            // 答案只有两列
            int x = deg_to_node[2];
            for (int y : g[x]) {
                if (g[y].size() == 2) {
                    row = {x, y};
                    break;
                }
            }
        } else {
            // 答案至少有三列
            int x = deg_to_node[2];
            row = {x};
            int pre = x;
            x = g[x][0];
            while (g[x].size() > 2) {
                row.push_back(x);
                for (int y : g[x]) {
                    if (y != pre && g[y].size() < 4) {
                        pre = x;
                        x = y;
                        break;
                    }
                }
            }
            row.push_back(x);
        }

        vector<int> vis(n);
        for (int x : row) {
            vis[x] = true;
        }
        vector<vector<int>> ans(n / row.size());
        ans[0] = move(row);
        for (int i = 1; i < ans.size(); i++) {
            for (int x : ans[i - 1]) {
                for (int y : g[x]) {
                    // x 上左右的邻居都访问过了，没访问过的邻居只会在 x 下面
                    if (!vis[y]) {
                        vis[y] = true;
                        ans[i].push_back(y);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

