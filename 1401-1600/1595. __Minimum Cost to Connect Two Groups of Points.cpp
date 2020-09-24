// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1595-minimum-cost-to-connect-two-groups-of-points/
class Solution {
public:
  int connectTwoGroups(vector<vector<int>>& cost) {
    constexpr int kInf = 1e9;
    const int m = cost.size();
    const int n = cost[0].size();
    // dp[i][s] := min cost to connect first i points in group1 
    // and points (bitmask s) in group2.
    vector<vector<int>> dp(m + 1, vector<int>(1 << n, kInf));
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int s = 0; s < 1 << n; ++s)
          dp[i + 1][s | (1 << j)] = min({dp[i + 1][s | (1 << j)], 
                                         dp[i + 1][s] + cost[i][j],
                                         dp[i][s] + cost[i][j]});
    return dp[m].back();
  }
};
