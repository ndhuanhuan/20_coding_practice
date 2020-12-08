// https://zxi.mytechroad.com/blog/bit/leetcode-1680-concatenation-of-consecutive-binary-numbers/
class Solution {
public:
  int concatenatedBinary(int n) {
    constexpr int kMod = 1e9 + 7;
    long ans = 0;    
    for (int i = 1, len = 0; i <= n; ++i) {
      if ((i & (i - 1)) == 0) ++len;
      ans = ((ans << len) % kMod + i) % kMod;
    }
    return ans;
  }
};
