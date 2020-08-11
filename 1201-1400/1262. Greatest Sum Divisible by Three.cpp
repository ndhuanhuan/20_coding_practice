// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1262-greatest-sum-divisible-by-three/
class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    vector<int> dp(3);    
    for (int num : nums) {
      vector<int> tmp(dp);
      for (int s : tmp)
        dp[(s + num) % 3] = max(dp[(s + num) % 3], s + num);      
    }
    return dp[0];
  }
}
