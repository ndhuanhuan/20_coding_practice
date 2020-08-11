// https://zxi.mytechroad.com/blog/heap/leetcode-778-swim-in-rising-water/
class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    priority_queue<pair<int, int>> q; // {-time, y * N + x}
    q.push({-grid[0][0], 0 * n + 0});
    vector<int> seen(n * n);
    vector<int> dirs{-1, 0, 1, 0, -1};
    seen[0 * n + 0] = 1;
    while (!q.empty()) {
      auto node = q.top(); q.pop();
      int t = -node.first;
      int x = node.second % n;
      int y = node.second / n;      
      if (x == n - 1 && y == n - 1) return t;
      for (int i = 0; i < 4; ++i) {
        int tx = x + dirs[i];
        int ty = y + dirs[i + 1];
        if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
        if (seen[ty * n + tx]) continue;
        seen[ty * n + tx] = 1;
        q.push({-max(t, grid[ty][tx]), ty * n + tx});
      }
    }
    return -1;
  }
};
