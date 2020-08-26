// https://zxi.mytechroad.com/blog/graph/leetcode-1557-minimum-number-of-vertices-to-reach-all-nodes/
class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> in(n);    
    for (const auto& e : edges) ++in[e[1]];
    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (in[i] == 0) ans.push_back(i);
    return ans;    
  }
};
