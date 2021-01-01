
// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1703-minimum-adjacent-swaps-for-k-consecutive-ones/
class Solution {
public:
  int minMoves(vector<int>& nums, int k) {
    vector<long> s(1);
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i])
        s.push_back(s.back() + i);
    const int n = s.size();
    long ans = 1e10;
    const int m1 = k / 2, m2 = (k + 1) / 2;
    for (int i = 0; i + k < n; ++i) {
      const long right = s[i + k] - s[i + m1];
      const long left = s[i + m2] - s[i];
      ans = min(ans, right - left);
    }
    return ans - m1 * m2;
  }
};
