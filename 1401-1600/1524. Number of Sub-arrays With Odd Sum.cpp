// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1524-number-of-sub-arrays-with-odd-sum/
class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    const int n = arr.size();
    constexpr int kMod = 1e9 + 7;
    // dp[i][0] # of subarrays ends with a[i-1] have even sums.
    // dp[i][1] # of subarrays ends with a[i-1] have odd sums.
    vector<vector<int>> dp(n + 1, vector<int>(2));
    long ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (arr[i - 1] & 1) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + 1;
      } else {
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = dp[i - 1][1];
      }
      ans += dp[i][1];
    }
    return ans % kMod;
  }
};
