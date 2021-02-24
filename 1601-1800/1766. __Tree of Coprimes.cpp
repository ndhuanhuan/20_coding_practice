// https://leetcode.com/problems/tree-of-coprimes/discuss/1074770/C%2B%2B-Save-the-cops
// https://zxi.mytechroad.com/blog/searching/leetcode-1766-tree-of-coprimes/
class Solution {
public:
  vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
    constexpr int kMax = 50;
    const int n = nums.size();
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }    
        
    vector<vector<int>> coprime(kMax + 1);
    for (int i = 1; i <= kMax; ++i)
      for (int j = 1; j <= kMax; ++j)
        if (gcd(i, j) == 1) coprime[i].push_back(j);
    
    vector<int> ans(n, INT_MAX);
    vector<vector<pair<int, int>>> p(kMax + 1);
    function<void(int, int)> dfs = [&](int cur, int d) {    
      int max_d = -1;
      int ancestor = -1;
      for (int co : coprime[nums[cur]])
        if (!p[co].empty() && p[co].back().first > max_d) {
          max_d = p[co].back().first;
          ancestor = p[co].back().second;          
        }
      ans[cur] = ancestor;
      p[nums[cur]].emplace_back(d, cur); // key is node value which can be duplicate from previous value. Basically we are storing a path from top to down in this p.
      for (int nxt : g[cur])
        if (ans[nxt] == INT_MAX) dfs(nxt, d + 1);
      p[nums[cur]].pop_back();
    };
    
    dfs(0, 0);
    return ans;
  }
};
