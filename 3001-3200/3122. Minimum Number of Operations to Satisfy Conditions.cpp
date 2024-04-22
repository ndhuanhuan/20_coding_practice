// https://leetcode.cn/problems/minimum-number-of-operations-to-satisfy-conditions/solutions/2749283/ji-yi-hua-sou-suo-pythonjavacgo-by-endle-8i0e/
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<array<int, 10>> cnt(n);
        for (auto& row : grid) {
            for (int j = 0; j < n; j++) {
                cnt[j][row[j]]++;
            }
        }

        vector<vector<int>> memo(n, vector<int>(11, -1)); // -1 表示没有计算过
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0) {
                return 0;
            }
            auto& res = memo[i][j]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            res = 0;
            for (int k = 0; k < 10; k++) {
                if (k != j) {
                    res = max(res, dfs(i - 1, k) + cnt[i][k]);
                }
            }
            return res;
        };
        return m * n - dfs(n - 1, 10);
    }
};
