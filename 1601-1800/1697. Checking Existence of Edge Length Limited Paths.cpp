// https://zxi.mytechroad.com/blog/graph/leetcode-1697-checking-existence-of-edge-length-limited-paths/
class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
    vector<int> parents(n);
    iota(begin(parents), end(parents), 0);
    function<int(int)> find = [&](int x) {
      return parents[x] == x ? x : parents[x] = find(parents[x]);
    };
    const int m = Q.size();
    for (int i = 0; i < m; ++i) Q[i].push_back(i);
    // Sort edges by weight in ascending order.
    sort(begin(E), end(E), [](const auto& a, const auto& b) { return a[2] < b[2]; });
    // Sort queries by limit in ascending order
    sort(begin(Q), end(Q), [](const auto& a, const auto& b) { return a[2] < b[2]; });
    vector<bool> ans(m);
    int i = 0;
    for (const auto& q : Q) {      
      while (i < E.size() && E[i][2] < q[2])
        parents[find(E[i++][0])] = find(E[i][1]);        
      ans[q[3]] = find(q[0]) == find(q[1]);
    }
    return ans;
  }
};
