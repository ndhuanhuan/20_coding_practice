// https://leetcode.cn/problems/longest-special-path/solutions/3051377/shu-shang-hua-chuang-pythonjavacgo-by-en-rh5m/
class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        pair<int, int> ans = {-1, 0};
        vector<int> dis = {0};
        unordered_map<int, int> last_depth; // 颜色 -> 该颜色最近一次出现的深度 +1，注意这里已经 +1 了

        auto dfs = [&](this auto&& dfs, int x, int fa, int top_depth) -> void {
            int color = nums[x];
            int old_depth = last_depth[color];
            top_depth = max(top_depth, old_depth);

            // 把 dis.size() - top_depth 取反，这样 max 算的是最小值
            ans = max(ans, pair(dis.back() - dis[top_depth], top_depth - (int) dis.size()));

            last_depth[color] = dis.size();
            for (auto& [y, w] : g[x]) {
                if (y != fa) { // 避免访问父节点
                    dis.push_back(dis.back() + w);
                    dfs(y, x, top_depth);
                    dis.pop_back(); // 恢复现场
                }
            }
            last_depth[color] = old_depth; // 恢复现场
        };

        dfs(0, -1, 0);
        return {ans.first, -ans.second};
    }
};

