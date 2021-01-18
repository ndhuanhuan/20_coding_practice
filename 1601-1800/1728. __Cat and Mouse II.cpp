// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1728-cat-and-mouse-ii/
class Solution {
public:
  bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {         
    const int m = grid.size(), n = grid[0].size();        
    int mouse, cat, food;
    for (int pos = 0; pos < m * n; ++pos)      
      switch (grid[pos / n][ pos % n]) {
        case 'M': mouse = pos; break;
        case 'C': cat = pos; break;
        case 'F': food = pos; break;
        default: break;
      }
    
    const vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    const int limit = m * n * 2;
    vector<vector<vector<int>>> seen(m*n, 
        vector<vector<int>>(m*n, vector<int>(limit + 1, -1)));
    function<bool(int, int, int)> dfs = 
      [&](int mouse, int cat, int d) -> bool {
        const bool isCat = d & 1;
        if (cat == food || cat == mouse || d >= limit) return isCat;
        if (mouse == food) return !isCat;
        int& ans = seen[mouse][cat][d];
        if (ans != -1) return ans;
        const int cur = isCat ? cat : mouse;
        const int jumps = isCat ? catJump : mouseJump;
        for (const auto& [dx, dy] : dirs)
          for (int j = 0; j <= jumps; ++j) {
            const int x = (cur % n) + dx * j;
            const int y = (cur / n) + dy * j;
            const int pos = y * n + x;
            if (x < 0 || x >= n || y < 0 || y >= m || grid[y][x] == '#') break;            
            if (!dfs(isCat ? mouse : pos, isCat ? pos : cat, d + 1)) return ans = true; 
          }
      return ans = false;
    };
    return dfs(mouse, cat, 0);
  }
};
