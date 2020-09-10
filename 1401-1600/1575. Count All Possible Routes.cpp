// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1575-count-all-possible-routes/
class Solution {
public:
  int countRoutes(vector<int>& x, int start, int finish, int fuel) {
    constexpr int kMod = 1e9 + 7;
    const int n = x.size();    
    vector<vector<int>> dp(n, vector<int>(fuel + 1));
    dp[start][fuel] = 1;
    for (int f = fuel; f > 0; --f)
      for (int i = 0; i < n; ++i) {
        if (!dp[i][f] || abs(x[i] - x[finish]) > f) continue; // pruning.
        for (int j = 0; j < n; ++j) {
          const int d = abs(x[i] - x[j]);                    
          if (i == j || f < d) continue;
          dp[j][f - d] = (dp[j][f - d] + dp[i][f]) % kMod;
        }
      }
    return accumulate(begin(dp[finish]), end(dp[finish]), 0LL) % kMod;        
  }
};
