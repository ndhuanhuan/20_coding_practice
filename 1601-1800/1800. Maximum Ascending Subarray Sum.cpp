// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1800-maximum-ascending-subarray-sum/
class Solution {
public:
  int maxAscendingSum(vector<int>& nums) {    
    int ans = 0;
    for (int i = 0, s = 0; i < nums.size(); ++i) {
      if (i && nums[i] <= nums[i - 1])
        s = 0;
      ans = max(ans, s += nums[i]);
    }
    return ans;
  }
};
