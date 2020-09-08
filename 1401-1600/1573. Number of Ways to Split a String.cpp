// https://zxi.mytechroad.com/blog/math/leetcode-1573-number-of-ways-to-split-a-string/
class Solution {
public:
  int numWays(string s) {
    const int kMod = 1e9 + 7;
    const long n = s.length();
    int t = 0;
    for (char c : s) t += c == '1';
    if (t % 3) return 0;
    if (t == 0)
      return ((1 + (n - 2)) * (n - 2) / 2) % kMod;
    t /= 3;
    long l = 0;
    long r = 0;
    for (int i = 0, c = 0; i < n; ++i) {
      c += (s[i] == '1');
      if (c == t) ++l;
      else if (c == t * 2) ++r;
    }
    return (l * r) % kMod;
  }
};
