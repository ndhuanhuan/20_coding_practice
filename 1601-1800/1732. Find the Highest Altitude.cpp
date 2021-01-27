// https://zxi.mytechroad.com/blog/algorithms/array/leetcode1732-find-the-highest-altitude/
class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int ans = 0;
    int cur = 0;
    for (int diff : gain)
      ans = max(ans, cur += diff);
    return ans;
  }
};
