// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1658-minimum-operations-to-reduce-x-to-zero/
class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    const int n = nums.size();
    int target = accumulate(begin(nums), end(nums), 0) - x;    
    int ans = INT_MAX;
    for (int s = 0, l = 0, r = 0; r < n; ++r) {
      s += nums[r];
      while (s > target && l <= r) s -= nums[l++];
      if (s == target) ans = min(ans, n - (r - l + 1));
    }
    return ans > n ? -1 : ans;
  }
};
