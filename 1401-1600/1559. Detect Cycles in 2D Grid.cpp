// https://zxi.mytechroad.com/blog/graph/leetcode-1559-detect-cycles-in-2d-grid/
class Solution {
public:
  bool containsCycle(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> seen(m, vector<int>(n));
    vector<int> dirs{0, 1, 0, -1, 0};
    function<bool(int, int, int, int)> dfs = [&](int i, int j, int pi, int pj) {
      ++seen[i][j];
      for (int d = 0; d < 4; ++d) {
        int ni = i + dirs[d];
        int nj = j + dirs[d + 1];
        if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
        if (grid[ni][nj] != grid[i][j]) continue;
        if (!seen[ni][nj]) {
          if (dfs(ni, nj, i, j)) return true;
        } else if (ni != pi || nj != pj) {
          return true;
        }       
      }
      return false;
    };    
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (!seen[i][j]++ && dfs(i, j, -1, -1)) 
          return true;
    return false;
  }
};
