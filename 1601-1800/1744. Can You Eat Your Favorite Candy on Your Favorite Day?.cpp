
// https://zxi.mytechroad.com/blog/math/leetcode-1744-can-you-eat-your-favorite-candy-on-your-favorite-day/
class Solution {
public:
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    const int n = candiesCount.size();
    vector<long> sums(n + 1);    
    for (int i = 1; i <= n; ++i)
      sums[i] += sums[i - 1] + candiesCount[i - 1];
    vector<bool> ans;
    for (const auto& q : queries) {
      const long type = q[0], days = q[1] + 1, cap = q[2];
      ans.push_back(days * cap > sums[type] && days <= sums[type + 1]);
    }
    return ans;
  }
};
