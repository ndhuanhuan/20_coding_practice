// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/discuss/969535/JavaPython-3-Prefix-Sum-O(n)-code-w-brief-explanation-and-analysis.
// https://zxi.mytechroad.com/blog/math/leetcode-1685-sum-of-absolute-differences-in-a-sorted-array/
class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);    
    for (int i = 1, sum = 0; i < n; ++i)
      ans[i] += (sum += (nums[i] - nums[i - 1]) * i);
    for (int i = n - 2, sum = 0; i >= 0; --i)
      ans[i] += (sum += (nums[i + 1] - nums[i]) * (n - i - 1));
    return ans;
  }
};
