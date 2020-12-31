// https://zxi.mytechroad.com/blog/simulation/leetcode-1701-average-waiting-time/
class Solution {
public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    int t = 0;
    double w = 0;
    for (const auto& c : customers) {
      if (c[0] > t) t = c[0];
      t += c[1];
      w += t - c[0];
    }
    return w / customers.size();
  }
};
