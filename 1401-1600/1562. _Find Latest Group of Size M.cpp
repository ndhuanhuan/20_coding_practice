// https://zxi.mytechroad.com/blog/hashtable/leetcode-1562-find-latest-group-of-size-m/
class Solution {
public:
  int findLatestStep(vector<int>& arr, int m) {
    const int n = arr.size();
    vector<int> len(n + 2);
    vector<int> counts(n + 2);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      const int x = arr[i];      
      const int l = len[x - 1];
      const int r = len[x + 1];
      const int t = 1 + l + r;  
      len[x - l] = len[x + r] = t;
      --counts[l];
      --counts[r];
      ++counts[t];
      if (counts[m]) ans = i + 1;
    }
    return ans;
  }
};
