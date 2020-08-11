// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-135-1037-1038-1039-1040/
class Solution {
public:
  int minScoreTriangulation(vector<int>& A) {
    const int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int l = 3; l <= n; ++l)
      for (int i = 0; i + l <= n; ++i) {        
        int j = i + l - 1;
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k <= j - 1; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
      }
    return dp[0][n - 1];
  }
};
