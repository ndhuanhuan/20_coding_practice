// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1751-maximum-number-of-events-that-can-be-attended-ii/
class Solution {
public:
  int maxValue(vector<vector<int>>& events, int k) {
    const int n = events.size(); 
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));    
    vector<int> e(n);
    auto comp = [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    };
    
    sort(begin(events), end(events), comp);
    
    for (int i = 1; i <= n; ++i) {
      const int p = lower_bound(begin(events), 
                                begin(events) + i, 
                                vector<int>{0, events[i - 1][0], 0},
                                comp) - begin(events);
      for (int j = 1; j <= k; ++j)
        dp[i][j] = max(dp[i - 1][j], 
                       dp[p][j - 1] + events[i - 1][2]);
    }    
    return dp[n][k];
  }
};
