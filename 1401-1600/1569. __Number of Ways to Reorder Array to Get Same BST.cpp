// https://zxi.mytechroad.com/blog/recursion/leetcode-1569-number-of-ways-to-reorder-array-to-get-same-bst/
// https://www.youtube.com/watch?v=NQfklbAqw80&t=10s
class Solution {
public:
  int numOfWays(vector<int>& nums) {
    const int n = nums.size();
    const int kMod = 1e9 + 7;
    vector<vector<int>> cnk(n + 1, vector<int>(n + 1, 1));    
    for (int i = 1; i <= n; ++i)      
      for (int j = 1; j < i; ++j)
        cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % kMod;    
    function<int(vector<int>)> trees = [&](const vector<int>& nums) {
      const int n = nums.size();
      if (n <= 2) return 1;
      vector<int> left;
      vector<int> right;
      for (int i = 1; i < nums.size(); ++i)
        if (nums[i] < nums[0]) left.push_back(nums[i]);
        else right.push_back(nums[i]);
      long ans = cnk[n - 1][left.size()];
      ans = (ans * trees(left)) % kMod;      
      ans = (ans * trees(right)) % kMod;      
      return static_cast<int>(ans);
    };
    return trees(nums) - 1;
  } 
};
