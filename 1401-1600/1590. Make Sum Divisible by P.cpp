// https://zxi.mytechroad.com/blog/hashtable/leetcode-1590-make-sum-divisible-by-p/
class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    const int n = nums.size();
    int r = accumulate(begin(nums), end(nums), 0LL) % p;
    if (r == 0) return 0;
    unordered_map<int, int> m{{0, -1}}; // {prefix_sum % p -> last_index}
    int s = 0;
    int ans = n;
    for (int i = 0; i < n; ++i) {
      s = (s + nums[i]) % p;
      auto it = m.find((s + p - r) % p);
      if (it != m.end())
        ans = min(ans, i - it->second);
      m[s] = i;
    }
    return ans == n ? -1 : ans;
  }
};
