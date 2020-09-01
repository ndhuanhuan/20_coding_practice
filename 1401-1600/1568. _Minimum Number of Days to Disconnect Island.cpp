// https://zxi.mytechroad.com/blog/graph/leetcode-1568-minimum-number-of-days-to-disconnect-island/
class Solution {
public:
  int minDays(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();    
    const vector<int> dirs{0, 1, 0, -1, 0};
    vector<int> seen(n * m);    
    function<void(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || y < 0 || x >= m || y >= n) return;
      if (grid[y][x] == 0) return;
      if (seen[y * m + x]++) return;      
      for (int i = 0; i < 4; ++i)        
        dfs(x + dirs[i], y + dirs[i + 1]);
    };
    
    function<bool()> disconnected = [&]() {
      int count = 0;
      fill(begin(seen), end(seen), 0);
      for (int y = 0; y < n; ++y)
        for (int x = 0; x < m; ++x)
          if (grid[y][x] && !seen[y * m + x]) {
            dfs(x, y);
            if (++count > 1) return true;
          }
      return false;
    };
    
    if (disconnected()) return 0;
    
    for (int y = 0; y < n; ++y)
      for (int x = 0; x < m; ++x) {
        if (!grid[y][x]) continue;
        grid[y][x] = 0;
        if (disconnected()) return 1;
        grid[y][x] = 1;
      }
    return 2;
  }
};
