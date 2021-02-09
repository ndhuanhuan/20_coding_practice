// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1749-maximum-absolute-sum-of-any-subarray/
class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    int lo = 0;
    int hi = 0;
    int s = 0;
    int ans = 0;
    for (int x : nums) {
      s += x;
      ans = max({ans, abs(s - lo), abs(s - hi)});
      hi = max(hi, s);
      lo = min(lo, s);
    }
    return ans;
  }
};
