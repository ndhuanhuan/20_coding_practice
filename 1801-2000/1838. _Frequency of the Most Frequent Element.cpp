// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1838-frequency-of-the-most-frequent-element/

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
    int l = 0;
    long sum = 0;
    int ans = 0;
    for (int r = 0; r < nums.size(); ++r) {
      sum += nums[r];      
      while (l < r && 
             sum + k < static_cast<long>(nums[r]) * (r - l + 1))
        sum -= nums[l++];
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
