// https://leetcode.com/problems/stamping-the-grid/discuss/1675412/JavaC%2B%2BPython-Calulate-the-sub-matrix-sum-twice
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& M, int h, int w) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> A(m + 1, vector<int>(n + 1)), B(m + 1, vector<int>(n + 1)), good(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i + 1][j + 1] = A[i + 1][j] + A[i][j + 1] - A[i][j] + (1 - M[i][j]);
                if (i + 1 >= h && j + 1 >= w) {
                    int x = i + 1 - h, y = j + 1 - w;
                    if (A[i + 1][j + 1] - A[x][j + 1] - A[i + 1][y] + A[x][y] == w * h)
                        good[i][j]++;
                }
            }
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + good[i][j];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = min(i + h, m), y = min(j + w, n);
                if (M[i][j] == 0 && B[x][y] - B[i][y] - B[x][j] + B[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
};
