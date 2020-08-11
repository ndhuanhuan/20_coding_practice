// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1312-minimum-insertion-steps-to-make-a-string-palindrome/
class Solution {
public:
  int minInsertions(string s) {
    const int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    
    for (int l = 2; l <= n; ++l)
      for (int i = 0, j = l - 1; j < n; ++i, ++j)        
        dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i + 1][j], dp[i][j - 1]) + 1;                        
    return dp[0][n - 1];
  }
};
