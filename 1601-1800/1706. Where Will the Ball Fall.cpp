// https://zxi.mytechroad.com/blog/simulation/leetcode-1706-where-will-the-ball-fall/
class Solution {
public:
  vector<int> findBall(vector<vector<int>>& G) {
    const int m = G.size();
    const int n = G[0].size();
    auto fall = [&](int x) -> int {
      for (int y = 0; y < m; ++y)
        if ((G[y][x] == -1 && (x == 0 || G[y][x - 1] == 1)) ||            
            (G[y][x] == 1 && (x == n - 1 || G[y][x + 1] == -1)))           
          return -1;
        else
          x += G[y][x];      
      return x;
    };
    vector<int> ans(n);
    for (int x = 0; x < n; ++x)
      ans[x] = fall(x);
    return ans;
  }
};
