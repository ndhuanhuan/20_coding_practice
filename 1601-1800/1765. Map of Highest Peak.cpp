// https://zxi.mytechroad.com/blog/searching/leetcode-1765-map-of-highest-peak/
class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    const int m = isWater.size();
    const int n = isWater[0].size();
    vector<vector<int>> ans(m, vector<int>(n, INT_MIN));
    queue<pair<int, int>> q;
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        if (isWater[y][x]) {
          q.emplace(x, y);
          ans[y][x] = 0;
        }
    const vector<int> dirs{0, -1, 0, 1, 0};    
    while (!q.empty()) {
      const auto [cx, cy] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        const int x = cx + dirs[i];
        const int y = cy + dirs[i + 1];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (ans[y][x] != INT_MIN) continue;
        ans[y][x] = ans[cy][cx] + 1;
        q.emplace(x, y);
      }      
    }
    return ans;
  }
};
