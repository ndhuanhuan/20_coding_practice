// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1652-defuse-the-bomb/
class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {    
    const int n = code.size();
    vector<int> ans(n);
    int sign = k > 0 ? 1 : -1;
    for (int i = 0; i < n; ++i)
      for (int j = 1; j <= abs(k); ++j)
        ans[i] += code[(i + j * sign + n) % n];
    return ans;
  }
};
