// https://zxi.mytechroad.com/blog/graph/leetcode-886-possible-bipartition/
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      g_ = vector<vector<int>>(N);
      for (const auto& d : dislikes) {
        g_[d[0] - 1].push_back(d[1] - 1);
        g_[d[1] - 1].push_back(d[0] - 1);
      }
      colors_ = vector<int>(N, 0);  // 0: unknown, 1: red, -1: blue
      for (int i = 0; i < N; ++i)
        if (colors_[i] == 0 && !dfs(i, 1)) return false;  //if no color, and try to add color, and fail, return false.
      return true;      
    }
private:
  vector<vector<int>> g_;
  vector<int> colors_;
  bool dfs(int cur, int color) {
    colors_[cur] = color;
    for (int nxt : g_[cur]) {
      if (colors_[nxt] == color) return false;      // node next to current node should has different color
      if (colors_[nxt] == 0 && !dfs(nxt, -color)) return false;
    }
    return true;
  }
};
