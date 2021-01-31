// https://zxi.mytechroad.com/blog/hashtable/leetcode-1743-restore-the-array-from-adjacent-pairs/
class Solution {
public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    const int n = adjacentPairs.size() + 1;
    unordered_map<int, vector<int>> g;
    for (const auto& p : adjacentPairs) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    
    vector<int> ans(n);
    for (const auto& [u, vs] : g)
      if (vs.size() == 1) {
        ans[0] = u;
        ans[1] = vs[0];
        break;
      }
        
    for (int i = 2; i < n; ++i) {
      const auto& vs = g[ans[i - 1]];
      ans[i] = vs[0] == ans[i - 2] ? vs[1] : vs[0];      
    }
    return ans;
  }
};
