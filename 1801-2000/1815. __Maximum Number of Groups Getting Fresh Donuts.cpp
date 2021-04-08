// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1815-maximum-number-of-groups-getting-fresh-donuts/
class Solution {
public:
  int maxHappyGroups(int b, vector<int>& groups) {
    int ans = 0;
    vector<int> count(b);
    for (int g : groups) ++count[g % b];      
    map<vector<int>, int> cache;
    function<int(int)> dp = [&](int s) {
      auto it = cache.find(count);
      if (it != cache.end()) return it->second;
      int ans = 0;
      for (int i = 1; i < b; ++i) {
        if (!count[i]) continue;
        --count[i];
        ans = max(ans, (s == 0) + dp((s + i) % b));
        ++count[i];
      }
      return cache[count] = ans;
    };    
    return count[0] + dp(0);
  }
};
