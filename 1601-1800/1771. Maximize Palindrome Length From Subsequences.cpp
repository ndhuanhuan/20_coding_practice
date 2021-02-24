// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1771-maximize-palindrome-length-from-subsequences/
class Solution {
public:
  int longestPalindrome(string word1, string word2) {
    const int l1 = word1.length();
    const int l2 = word2.length();
    string s = word1 + word2;
    const int n = l1 + l2;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int l = 2; l <= n; ++l)
      for (int i = 0, j = i + l - 1; j < n; ++i, ++j) {
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1] + 2;
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    
    int ans = 0;
    for (int i = 0; i < l1; ++i)
      for (int j = 0; j < l2; ++j)
        if (word1[i] == word2[j])
          ans = max(ans, dp[i][l1 + j]);
    return ans;
  }
};
