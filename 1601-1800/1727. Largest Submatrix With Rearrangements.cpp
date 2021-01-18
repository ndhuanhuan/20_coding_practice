// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1727-largest-submatrix-with-rearrangements/
class Solution {
public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    for (int j = 0; j < n; ++j)
      for (int i = 1; i < m; ++i)      
        if (matrix[i][j]) matrix[i][j] += matrix[i - 1][j];          
    
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      sort(rbegin(matrix[i]), rend(matrix[i]));
      for (int j = 0; j < n; ++j)
        ans = max(ans, (j + 1) * matrix[i][j]);        
    }
    return ans;    
  }
};
