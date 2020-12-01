// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1671-minimum-number-of-removals-to-make-mountain-array/
class Solution {
public:
  int minimumMountainRemovals(vector<int>& nums) {
    const int n = nums.size();
    vector<int> LIS(n, 1); // LIS[i] := Longest increasing subseq ends with nums[i]
    vector<int> LDS(n, 1); // LDS[i] := Longest decreasing subseq starts with nums[i]
    for (int i = 0; i < n; ++i)      
      for (int j = 0; j < i; ++j)
        if (nums[i] > nums[j]) LIS[i] = max(LIS[i], LIS[j] + 1);
    for (int i = n - 1; i >= 0; --i)
      for (int j = n - 1; j > i; --j)
        if (nums[i] > nums[j]) LDS[i] = max(LDS[i], LDS[j] + 1);
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (LIS[i] < 2 || LDS[i] < 2) continue;
      ans = min(ans, n - (LIS[i] + LDS[i] - 1));
    }
    return ans;
  }
};
