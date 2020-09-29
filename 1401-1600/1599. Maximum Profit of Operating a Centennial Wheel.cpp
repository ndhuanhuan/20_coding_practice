// https://zxi.mytechroad.com/blog/simulation/leetcode-1599-maximum-profit-of-operating-a-centennial-wheel/
class Solution {
public:
  int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
    const int n = customers.size();
    constexpr int kMaxC = 4;
    if (runningCost > kMaxC * boardingCost) return -1;
    int c = 0;
    int ans = -1;
    int p = 0;
    int max_p = 0;    
    for (int r = 0; r < n || c > 0; ++r) {
      c += (r < n ? customers[r] : 0);      
      p += min(c, kMaxC) * boardingCost - runningCost;      
      c -= min(c, kMaxC);
      if (p > max_p) {
        max_p = p;
        ans = r + 1; // 1-based
      }
    }
    return ans;
  }
};
