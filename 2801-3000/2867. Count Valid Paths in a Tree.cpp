const int MX = 1e5;
bool np[MX + 1]; // 质数=false 非质数=true
int init = []() {
    np[1] = true;
    for (int i = 2; i * i <= MX; i++) {
        if (!np[i]) {
            for (int j = i * i; j <= MX; j += i) {
                np[j] = true;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    long long countPaths(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n + 1);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> size(n + 1);
        vector<int> nodes;
        function<void(int, int)> dfs = [&](int x, int fa) {
            nodes.push_back(x);
            for (int y: g[x]) {
                if (y != fa && np[y]) {
                    dfs(y, x);
                }
            }
        };

        long long ans = 0;
        for (int x = 1; x <= n; x++) {
            if (np[x]) continue; // 跳过非质数
            int sum = 0;
            for (int y: g[x]) { // 质数 x 把这棵树分成了若干个连通块
                if (!np[y]) continue;
                if (size[y] == 0) { // 尚未计算过
                    nodes.clear();
                    dfs(y, -1); // 遍历 y 所在连通块，在不经过质数的前提下，统计有多少个非质数
                    for (int z: nodes) {
                        size[z] = nodes.size();
                    }
                }
                // 这 size[y] 个非质数与之前遍历到的 sum 个非质数，两两之间的路径只包含质数 x
                ans += (long long) size[y] * sum;
                sum += size[y];
            }
            ans += sum; // 从 x 出发的路径
        }
        return ans;
    }
};

