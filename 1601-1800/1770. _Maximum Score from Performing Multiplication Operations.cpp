// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1770-maximum-score-from-performing-multiplication-operations/
class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    const int m = multipliers.size();
    const int n = nums.size();
    vector<vector<int>> cache(m, vector<int>(m, INT_MIN));
    function<int(int, int)> dp = [&](int l, int r) {
      const int k = n - (r - l + 1);
      if (k == m) return 0;
      int& ans = cache[l][k];
      if (ans != INT_MIN) return ans;
      return ans = max(dp(l + 1, r) + nums[l] * multipliers[k],
                       dp(l, r - 1) + nums[r] * multipliers[k]);
    };
    return dp(0, n - 1);
  }
};
