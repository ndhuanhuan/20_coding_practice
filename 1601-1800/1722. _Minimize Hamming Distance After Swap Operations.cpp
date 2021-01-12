// https://zxi.mytechroad.com/blog/uncategorized/leetcode-1722-minimize-hamming-distance-after-swap-operations/
class Solution {
public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    const int n = source.size();
    vector<int> p(n);
    iota(begin(p), end(p), 0);
    
    function<int(int)> find = [&](int x) {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    
    for (const auto& s : allowedSwaps)
      p[find(s[0])] = find(s[1]);
    
    unordered_map<int, unordered_map<int, int>> m;
    for (int i = 0; i < n; ++i) {
      ++m[find(i)][source[i]];
      --m[find(i)][target[i]];
    }
    
    int ans = 0;
    for (const auto& g : m) 
      for (const auto& kv : g.second)
        ans += abs(kv.second);
    return ans / 2;
  }
};
