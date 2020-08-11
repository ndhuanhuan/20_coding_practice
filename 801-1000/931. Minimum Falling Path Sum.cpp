//https://leetcode.com/problems/minimum-falling-path-sum/discuss/186666/C++Java-4-lines-DP
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
      for (auto i = 1; i < A.size(); ++i)
        for (auto j = 0; j < A.size(); ++j)
          A[i][j] += min(A[i-1][j], min(A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)]));
      return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));
    }
};
