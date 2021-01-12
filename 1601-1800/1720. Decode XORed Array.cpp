// https://zxi.mytechroad.com/blog/bit/leetcode-1720-decode-xored-array/
class Solution {
public:
  vector<int> decode(vector<int>& encoded, int first) {
    const int n = encoded.size() + 1;
    vector<int> ans(n, first);
    for (int i = 0; i + 1 < n; ++i)
      ans[i + 1] = ans[i] ^ encoded[i];
    return ans;
  }
};
