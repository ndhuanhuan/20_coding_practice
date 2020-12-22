// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1695-maximum-erasure-value/
class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    const int n = nums.size();
    unordered_set<int> t;
    int ans = 0;
    for (int l = 0, r = 0, s = 0; r < n; ++r) {
      while (t.count(nums[r]) && l < r) {
        s -= nums[l];
        t.erase(nums[l++]);
      }      
      t.insert(nums[r]);
      ans = max(ans, s += nums[r]);
    }
    return ans;
  }
};
