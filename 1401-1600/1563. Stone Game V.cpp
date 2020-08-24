// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1563-stone-game-v/
class Solution {
public:
  int stoneGameV(vector<int>& stoneValue) {
    const int n = stoneValue.size();
    vector<int> sums(n + 1);
    for (int i = 0; i < n; ++i)
      sums[i + 1] = sums[i] + stoneValue[i];
    vector<vector<int>> cache(n, vector<int>(n, -1));
    // max value alice can get from range [l, r]
    function<int(int, int)> dp = [&](int l, int r) {
      if (l == r) return 0;
      int& ans = cache[l][r];
      if (ans != -1) return ans;
      for (int k = l; k < r; ++k) {
        // left: [l, k], right: [k + 1, r]
        int sum_l = sums[k + 1] - sums[l];
        int sum_r = sums[r + 1] - sums[k + 1];
        if (sum_l > sum_r)
          ans = max(ans, sum_r + dp(k + 1, r));
        else if (sum_l < sum_r)
          ans = max(ans, sum_l + dp(l, k));
        else
          ans = max(ans, sum_l + max(dp(l, k), dp(k + 1, r)));
      }      
      return ans;
    };
    
    return dp(0, n - 1);
  }
};
