
// https://zxi.mytechroad.com/blog/greedy/leetcode-1702-maximum-binary-string-after-change/
class Solution {
public:
  string maximumBinaryString(string s) {
    const int n = s.length();
    int l = 0;
    int z = 0;
    for (char& c : s) {
      if (c == '0') {
        ++z;
      } else if (z == 0) { // leading 1s      
        ++l;
      }
      c = '1';
    }
    if (l != n) s[l + z - 1] = '0';
    return s;
  }
};
