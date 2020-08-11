// https://zxi.mytechroad.com/blog/string/leetcode-1541-minimum-insertions-to-balance-a-parentheses-string/
class Solution {
public:
  int minInsertions(string s) {
    int ans = 0;
    int close = 0; // # of ')' needed.    
    for (char c : s) {
      if (c == ')') {
        if (--close < 0) {          
          // need to insert one '('
          // ')' -> '()'
          ++ans;
          close += 2;
        }
      } else {
        if (close & 1) {          
          // need to insert one ')'
          // case '(()(' -> '(())('
          --close;
          ++ans;
        }
        close += 2; // need two ')'s
      }
    }
    return ans + close;
  }
};
