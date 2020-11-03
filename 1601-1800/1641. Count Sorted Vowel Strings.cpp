// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1641-count-sorted-vowel-strings/
class Solution {
public:
  int countVowelStrings(int n) {
    // dp[i][j] = # of strings of length i ends with j
    vector<vector<int>> dp(n + 1, vector<int>(5, 1));
    for (int i = 2; i <= n; ++i) {
      int s = 0;
      for (int j = 0; j < 5; ++j) {
        s += dp[i - 1][j];
        dp[i][j] = s;        
      }
    }
    return accumulate(begin(dp[n]), end(dp[n]), 0);
  }
};
