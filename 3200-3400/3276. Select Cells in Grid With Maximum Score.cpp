// https://leetcode.cn/problems/select-cells-in-grid-with-maximum-score/solutions/2899994/zhi-yu-zhuang-ya-dppythonjavacgo-by-endl-x27y/
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        unordered_map<int, int> pos;
        int m = grid.size();
        for (int i = 0; i < m; i++) {
            for (int x : grid[i]) {
                // 保存所有包含 x 的行号（压缩成二进制数）
                pos[x] |= 1 << i;
            }
        }

        // 只考虑在 grid 中的元素
        vector<int> all_nums;
        for (auto& [x, _] : pos) {
            all_nums.push_back(x);
        }

        int n = all_nums.size();
        vector<vector<int>> memo(n, vector<int>(1 << m, -1)); // -1 表示没有计算过
        auto dfs = [&](auto&& dfs, int i, int j) -> int {
            if (i < 0) {
                return 0;
            }
            int& res = memo[i][j]; // 注意这里是引用
            if (res != -1) {
                return res;
            }
            // 不选 x
            res = dfs(dfs, i - 1, j);
            // 枚举选第 k 行的 x
            int x = all_nums[i];
            for (int t = pos[x], lb; t; t ^= lb) {
                lb = t & -t; // lb = 1<<k，其中 k 是行号
                if ((j & lb) == 0) { // 没选过第 k 行的数
                    res = max(res, dfs(dfs, i - 1, j | lb) + x);
                }
            }
            return res;
        };
        return dfs(dfs, n - 1, 0);
    }
};

