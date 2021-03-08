// https://zxi.mytechroad.com/blog/graph/leetcode-1786-number-of-restricted-paths-from-first-to-last-node/
class Solution {
public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    constexpr int kMod = 1e9 + 7;
    using PII = pair<int, int>;    
    vector<vector<PII>> g(n + 1);
    for (const auto& e : edges) {
      g[e[0]].emplace_back(e[1], e[2]);
      g[e[1]].emplace_back(e[0], e[2]);
    }    
    
    // Shortest distance from n to x.
    vector<int> dist(n + 1, INT_MAX / 2);
    dist[n] = 0;
    priority_queue<PII, vector<PII>, std::greater<PII>> q;
    q.emplace(0, n);
    while (!q.empty()) {
      const auto [d, u] = q.top(); q.pop();
      if (dist[u] < d) continue;
      for (auto [v, w]: g[u]) {
        if (dist[u] + w >= dist[v]) continue;
        dist[v] = dist[u] + w;
        q.emplace(dist[v], v);
      }
    }
 
    vector<int> dp(n + 1, INT_MAX);
    function<int(int)> dfs = [&](int u) {      
      if (u == n) return 1;
      if (dp[u] != INT_MAX) return dp[u];
      int ans = 0;
      for (auto [v, w]: g[u])
        if (dist[u] > dist[v])
          ans = (ans + dfs(v)) % kMod;      
      return dp[u] = ans;
    };
    
    return dfs(1);
  }
};
