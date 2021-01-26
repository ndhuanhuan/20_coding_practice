// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1738-find-kth-largest-xor-coordinate-value/
class Solution {
public:
  int kthLargestValue(vector<vector<int>>& matrix, int k) {    
    const int m = matrix.size(), n = matrix[0].size();
    vector<int> v;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        v.push_back(matrix[i][j] 
                      ^= (i ? matrix[i - 1][j] : 0) 
                       ^ (j ? matrix[i][j - 1] : 0) 
                       ^ (i * j ? matrix[i - 1][j - 1] : 0));
    nth_element(begin(v), begin(v) + k - 1, end(v), greater<int>());    
    return v[k - 1];
  }
};
