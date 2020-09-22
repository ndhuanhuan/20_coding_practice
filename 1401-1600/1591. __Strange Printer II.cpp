// https://zxi.mytechroad.com/blog/graph/leetcode-1591-strange-printer-ii/
class Solution {
public:
  bool isPrintable(vector<vector<int>>& targetGrid) {
    constexpr int kMaxC = 60;
    const int m = targetGrid.size();
    const int n = targetGrid[0].size();
    vector<unordered_set<int>> deps(kMaxC + 1);
    for (int c = 1; c <= kMaxC; ++c) {
      int l = n, r = -1, t = m, b = -1;      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (targetGrid[i][j] == c)
            l = min(l, j), r = max(r, j), t = min(t, i), b = max(b, i);
      if (l == -1) continue;
      for (int i = t; i <= b; ++i)
        for (int j = l; j <= r; ++j)
          if (targetGrid[i][j] != c) 
            deps[c].insert(targetGrid[i][j]);
    }
    vector<int> seen(kMaxC + 1);
    function<bool(int)> hasCycle = [&](int c) {
      if (seen[c] == 1) return true;
      if (seen[c] == 2) return false;
      seen[c] = 1;
      for (int t : deps[c])
        if (hasCycle(t)) return true;
      seen[c] = 2;
      return false;
    };
    for (int c = 1; c <= kMaxC; ++c)
      if (hasCycle(c)) return false;
    return true;
  }
};
