// https://zxi.mytechroad.com/blog/hashtable/leetcode-1711-count-good-meals/

class Solution {
public:
  int countPairs(vector<int>& A) {
    constexpr int kMod = 1e9 + 7;
    unordered_map<int, int> m;    
    long ans = 0;
    for (int x : A) {
      for (int t = 1; t <= 1 << 21; t *= 2) {
        auto it = m.find(t - x);
        if (it != end(m)) ans += it->second;
      }
      ++m[x];
    }
    return ans % kMod;
  }
};
