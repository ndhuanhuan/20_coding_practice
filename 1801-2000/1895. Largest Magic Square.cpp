class Solution {
public:
    int m, n;
    vector<vector<int>> preSumRow, preSumCol;
    int largestMagicSquare(vector<vector<int>> &grid) {
        m = grid.size(); n = grid[0].size();
        preSumRow = vector(m, vector<int>(n + 1, 0)); preSumCol = vector(n, vector<int>(m + 1, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                preSumRow[r][c + 1] = preSumRow[r][c] + grid[r][c];
                preSumCol[c][r + 1] = preSumCol[c][r] + grid[r][c];
            }
        }
        for (int k = min(m, n); k >= 2; k--) if (test(grid, k)) return k; // the first valid `k` is the maximum result
        return 1;
    }
    bool test(vector<vector<int>> &grid, int k) {
        for (int r = 0; r + k - 1 < m; ++r) {
            for (int c = 0; c + k - 1 < n; ++c) {
                bool flg{true};
                int diag = 0, antiDiag = 0;
                for (int d = 0; d < k; ++d) {
                    diag += grid[r + d][c + d];
                    antiDiag += grid[r + d][c + k - 1 - d];
                }
                flg = diag == antiDiag;
                for (int nr = r; nr < r + k && flg; ++nr) if(diag != getSumRow(nr, c, c + k - 1)) flg = false;
                for (int nc = c; nc < c + k && flg; ++nc) if(diag != getSumCol(nc, r, r + k - 1)) flg = false;
                if (flg) return true;
            }
        }
        return false;
    }
    int getSumRow(int row, int l, int r) { // row, l, r inclusive
        return preSumRow[row][r + 1] - preSumRow[row][l];
    }
    int getSumCol(int col, int l, int r) { // row, l, r inclusive
        return preSumCol[col][r + 1] - preSumCol[col][l];
    }
};
