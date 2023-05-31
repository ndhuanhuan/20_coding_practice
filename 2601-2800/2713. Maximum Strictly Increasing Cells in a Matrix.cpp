// https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/solution/dong-tai-gui-hua-you-hua-pythonjavacgo-b-axv0/
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>> &mat) {
        map<int, vector<pair<int, int>>> g;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                g[mat[i][j]].emplace_back(i, j); // 相同元素放在同一组，统计位置

        int ans = 0;
        vector<int> row_max(m), col_max(n);
        for (auto &[_, pos]: g) {
            vector<int> mx; // 先把最大值算出来，再更新 row_max 和 col_max
            for (auto &[i, j]: pos) {
                mx.push_back(max(row_max[i], col_max[j]) + 1);
                ans = max(ans, mx.back());
            }
            for (int k = 0; k < pos.size(); k++) {
                auto &[i, j] = pos[k];
                row_max[i] = max(row_max[i], mx[k]); // 更新第 i 行的最大 f 值
                col_max[j] = max(col_max[j], mx[k]); // 更新第 j 列的最大 f 值
            }
        }
        return ans;
    }
};
