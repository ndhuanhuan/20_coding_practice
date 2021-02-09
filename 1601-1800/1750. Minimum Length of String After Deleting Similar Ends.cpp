// https://zxi.mytechroad.com/blog/greedy/leetcode-1750-minimum-length-of-string-after-deleting-similar-ends/
class Solution {
public:
  int minimumLength(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
      if (s[l] != s[r]) break;
      const char c = s[l];
      while (l <= r && s[l] == c) ++l;
      while (l <= r && s[r] == c) --r;
    }
    return r - l + 1;
  }
};
