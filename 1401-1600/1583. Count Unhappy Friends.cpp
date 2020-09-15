// https://zxi.mytechroad.com/blog/hashtable/leetcode-1583-count-unhappy-friends/
class Solution {
public:
  int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    vector<int> p(n);
    for (const auto& pair : pairs) {
      p[pair[0]] = pair[1];
      p[pair[1]] = pair[0];
    }
    vector<vector<int>> orders(n, vector<int>(n));
    for (int x = 0; x < n; ++x)
      for (int i = 0; i < preferences[x].size(); ++i)
        orders[x][preferences[x][i]] = i;
    int ans = 0;
    for (int x = 0; x < n; ++x) {
      const int y = p[x];      
      bool found = false;      
      for (int u = 0; u < n && !found; ++u) {
        if (u == x || u == y) continue;
        const int v = p[u];
        found |= orders[x][u] < orders[x][y] && orders[u][x] < orders[u][v]; 
      }
      if (found) ++ans;
    }
    return ans;
  }
};
