// https://zxi.mytechroad.com/blog/searching/leetcode-1593-split-a-string-into-the-max-number-of-unique-substrings/
class Solution {
public:
  int maxUniqueSplit(string_view s) {
    const int n = s.length();
    if (n == 1) return 1;
    size_t ans = 1;
    unordered_set<string_view> seen;
    for (int m = 1; m < 1 << (n - 1); ++m) {
      if (__builtin_popcount(m) < ans) continue; // 956 ms -> 52 ms
      bool valid = true;
      int p = 0;
      for (int i = 1; i <= n && valid; ++i) {
        if (m & (1 << (i - 1)) || i == n) {
          valid &= seen.insert(s.substr(p, i - p)).second;
          p = i;
        }
      }
      if (valid) ans = max(ans, seen.size());
      seen.clear();
    }
    return ans;
  }
};
