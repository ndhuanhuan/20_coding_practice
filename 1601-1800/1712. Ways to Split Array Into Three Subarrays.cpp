// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1712-ways-to-split-array-into-three-subarrays/
class Solution {
public:
  int waysToSplit(vector<int>& nums) {
    constexpr int kMod = 1e9 + 7;
    const int n = nums.size();    
    for (int i = 1; i < n; ++i) 
      nums[i] += nums[i - 1];
    const int total = nums.back();
    long ans = 0;    
    for (int i = 0, j = 0, k = 0; i < n; ++i) {      
      j = max(j, i + 1);
      while (j < n - 1 && nums[j] < 2 * nums[i]) ++j;
      k = max(k, j);
      while (k < n - 1 && 2 * nums[k] <= nums[i] + total) ++k;
      ans += (k - j);
    }    
    return ans % kMod;
  }
};
