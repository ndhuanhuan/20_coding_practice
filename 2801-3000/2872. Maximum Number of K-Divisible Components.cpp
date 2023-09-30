// https://leetcode.cn/problems/maximum-number-of-k-divisible-components/solutions/2464597/yi-ti-yi-jie-dong-tai-gui-hua-kotlinpyth-r1bn/
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // 建图
        vector<list<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // DFS <cnt, left>
        function<vector<int>(int, int)> dfs = [&](int i, int pre) -> vector<int> {
            vector<int> ret(2, 0); // [0, 0]
            ret[1] = values[i];
            for (int to : graph[i]) {
                if (to == pre) continue;
                vector<int> child = dfs(to, i);
                ret[0] += child[0];
                ret[1] += child[1];
            }
            if (ret[1] % k == 0) {
                ret[0] += 1;
                ret[1] = 0;
            }
            return ret;
        };
        return dfs(0, -1)[0];
    }
};

