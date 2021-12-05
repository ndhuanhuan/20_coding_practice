https://zxi.mytechroad.com/blog/graph/leetcode-2097-valid-arrangement-of-pairs/
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        const int n = pairs.size();
        unordered_map<int, stack<int>> g;
        unordered_map<int, int> in;
        unordered_map<int, int> out;    
        for (const auto& p : pairs) {
          g[p[0]].push(p[1]);
          ++out[p[0]];
          ++in[p[1]];
        }
        
        int s = pairs[0][0];
        for (const auto& [u, d] : out)
          if (out[u] - in[u] == 1) s = u;

        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int u) {      
          while (!g[u].empty()) {
            int v = g[u].top(); g[u].pop();
            dfs(v);
            ans.push_back({u, v});
          }
        };
        dfs(s);
        return {rbegin(ans), rend(ans)};
    }
};
