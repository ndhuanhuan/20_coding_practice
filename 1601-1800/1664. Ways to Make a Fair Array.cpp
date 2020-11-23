// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1664-ways-to-make-a-fair-array/
class Solution {
public:
  int waysToMakeFair(vector<int>& nums) {
    int n = nums.size();
    vector<int> odds(n + 1);
    vector<int> evens(n + 1);
    for (int i = 0; i < n; ++i) {      
      odds[i + 1] = odds[i] + (i % 2 == 1) * nums[i];
      evens[i + 1] = evens[i] + (i % 2 == 0) * nums[i];      
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      const int odd = odds[i] + (evens[n] - evens[i + 1]);
      const int even = evens[i] + (odds[n] - odds[i + 1]);
      ans += odd == even;
    }
    return ans;
  }
};
