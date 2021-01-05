// https://zxi.mytechroad.com/blog/greedy/leetcode-1710-maximum-units-on-a-truck/
class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(begin(boxTypes), end(boxTypes), [](const auto& a, const auto& b){
      return a[1] > b[1]; // Sort by unit DESC
    });
    
    int ans = 0;
    for (const auto& b : boxTypes) {      
      ans += b[1] * min(b[0], truckSize);      
      if ((truckSize -= b[0]) <= 0) break;      
    }
    return ans;
  }
};
