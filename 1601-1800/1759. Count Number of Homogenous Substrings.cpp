// https://zxi.mytechroad.com/blog/string/leetcode-1759-count-number-of-homogenous-substrings/
class Solution {
public:
  int countHomogenous(string s) {
    constexpr int kMod = 1e9 + 7;
    const int n = s.length();
    long ans = 0;
    for (long i = 0, j = 0; i < n; i = j) {
      while (j < n && s[i] == s[j]) ++j;
      ans += (j - i) * (j - i + 1) / 2;
    }
    return ans % kMod;
  }
};
