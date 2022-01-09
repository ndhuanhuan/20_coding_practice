class Solution {
public:
    bool checkValid(vector<vector<int>>& m) {
        int n = m.size(), x = 0;
        for (int i = 1; i <= n; ++i)
            x ^= i;
        for (int i = 0; i < m.size(); ++i) {
            int row = x, col = x;
            for (int j = 0; j <  m.size(); ++j) {
                row ^= m[i][j];
                col ^= m[j][i];
            }
            if (max(row, col) != 0)
                return false;
        }
        return true;
    }
};
