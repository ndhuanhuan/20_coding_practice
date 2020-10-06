// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/discuss/876845/JavaC%2B%2BPython-Easy-and-Concise-with-Prove
// https://zxi.mytechroad.com/blog/greedy/leetcode-1605-find-valid-matrix-given-row-and-column-sums/
// Picking the largest value possible corresponds to picking the min(rowSum, colSum). Since total(rowSum) = total(colSum), initially we had the equation that 3 + r2 + r3 + .. + rN = 4 + c2 + c3 + .. + cM. Since we use 3 as the value for the current cell, our new equation becomes 0 + r2 + r3 + .. + rN = 1 + c2 + c3 + .. + cM, which follows from the equation earlier. So as @lee215 mentioned, we haven't broken anything, the total(rowSum) = total(colSum) condition still holds.
class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    const int m = rowSum.size();
    const int n = colSum.size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        ans[i][j] = min(rowSum[i], colSum[j]);
        rowSum[i] -= ans[i][j];
        colSum[j] -= ans[i][j];
      }
    return ans;
  }
};
