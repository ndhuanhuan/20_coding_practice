// https://zxi.mytechroad.com/blog/hashtable/leetcode-2122-recover-the-original-array/
class Solution {
public:
  vector<int> recoverArray(vector<int>& nums) {
    const int n = nums.size();
    sort(begin(nums), end(nums));
    unordered_map<int, int> m;
    for (int x : nums) ++m[x];
    
    auto check = [&](int k) -> vector<int> {      
      vector<int> ans;
      unordered_map<int, int> cur(m);
      for (int x : nums) {
        if (cur[x] == 0) continue;
        --cur[x];
        if (--cur[x + 2 * k] < 0) return {};
        ans.push_back(x + k);
      }
      return ans;
    };
    for (int i = 1; i < n; ++i) {
      if (nums[i] == nums[0] || (nums[i] - nums[0]) & 1) continue;
      const int k = (nums[i] - nums[0]) / 2;
      vector<int> ans = check(k);
      if (!ans.empty()) return ans;
    }
    return {};
  }
};
