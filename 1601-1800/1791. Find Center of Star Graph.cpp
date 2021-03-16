// https://zxi.mytechroad.com/blog/graph/leetcode-1791-find-center-of-star-graph/
class Solution {
public:
  int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, int> degrees;
    for (const auto& e : edges) {
      ++degrees[e[0]];
      ++degrees[e[1]];
    }
    const int n = degrees.size();
    for (const auto& [id, d] : degrees)
      if (d == n - 1) return id;
    return -1;
  }
};
