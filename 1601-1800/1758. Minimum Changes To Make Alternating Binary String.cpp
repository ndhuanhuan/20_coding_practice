// https://zxi.mytechroad.com/blog/string/leetcode-1758-minimum-changes-to-make-alternating-binary-string/
class Solution {
public:
  int minOperations(string s) {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < s.length(); ++i) {
      c1 += (s[i] - '0' == i % 2);
      c2 += (s[i] - '0' != i % 2);
    }
    return min(c1, c2);
  }
};
