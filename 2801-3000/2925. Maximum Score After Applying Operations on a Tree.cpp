// https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree/solutions/2513101/shu-xing-dpxuan-huo-bu-xuan-pythonjavacg-7aj6/
// 核心：假如x是root，那么假如他的child node构成的子树是健康的，那它一定也是健康的。那么就可以有两种选择，选x，还是选子树健康。注意子树健康是累加的loss += dfs(y, x);
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &values) {
        vector<vector<int>> g(values.size());
        g[0].push_back(-1); // 避免误把根节点当作叶子
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // dfs(x, fa) 计算以 x 为根的子树是健康时，失去的最小分数
        function<long long(int, int)> dfs = [&](int x, int fa) -> long long {
            if (g[x].size() == 1) { // x 是叶子
                return values[x];
            }
            long long loss = 0; // 不选 values[x]
            for (int y: g[x]) {
                if (y != fa) {
                    loss += dfs(y, x); // 计算以 y 为根的子树是健康时，失去的最小分数
                }
            }
            return min((long long) values[x], loss); // 选/不选 values[x]，取最小值
        };
        return accumulate(values.begin(), values.end(), 0LL) - dfs(0, -1);
    }
};

