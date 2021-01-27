// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1735-count-ways-to-make-array-with-product/
class Solution {
public:
  vector<int> waysToFillArray(vector<vector<int>>& queries) {
    constexpr int kMod = 1e9 + 7;
    int n = 0;
    unordered_map<int, int> c, dp;
    function<int(int, int)> cnk = [&](int n, int k) {
      if (k > n) return 0;
      if (k == 0 || k == n) return 1;      
      int& ans = c[(n << 16) | k];
      if (!ans) ans = (cnk(n - 1, k - 1) + cnk(n - 1, k)) % kMod; 
      return ans;      
    };
    
    function<int(int, int)> dfs = [&](int s, int k) -> int {
      if (s == 0) return k == 1;
      if (k == 1) return cnk(n, s);
      int& ans = dp[(s << 16) | k];
      if (ans) return ans;      
      for (int i = 1; i * i <= k; ++i) {
        if (k % i) continue;
        if (i != 1) 
          ans = (ans + dfs(s - 1, k / i)) % kMod;
        if (i * i != k)
          ans = (ans + dfs(s - 1, i)) % kMod;
      }
      return ans;
    };
    
    vector<int> ans;
    for (const auto& q : queries) {
      dp.clear();
      n = q[0];
      ans.push_back(dfs(n, q[1]));
    }
    return ans;
  }
};
