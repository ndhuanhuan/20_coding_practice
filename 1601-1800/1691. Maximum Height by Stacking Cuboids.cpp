// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1691-maximum-height-by-stacking-cuboids/
class Solution {
public:
  int maxHeight(vector<vector<int>>& A) {
    A.push_back({0, 0, 0});
    const int n = A.size();
    for (auto& box : A) sort(begin(box), end(box));
    sort(begin(A), end(A));
    vector<int> dp(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (A[i][0] >= A[j][0] && A[i][1] >= A[j][1] && A[i][2] >= A[j][2])
          dp[i] = max(dp[i], dp[j] + A[i][2]);
    return *max_element(begin(dp), end(dp));
  }
};
