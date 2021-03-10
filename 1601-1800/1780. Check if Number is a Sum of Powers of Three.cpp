// https://zxi.mytechroad.com/blog/math/leetcode-1780-check-if-number-is-a-sum-of-powers-of-three/
class Solution {
public:
  bool checkPowersOfThree(int n) {
    int last = INT_MAX;
    while (n) {
      int p = 0;
      int cur = 1;
      while (cur * 3 <= n) {
        cur *= 3;
        ++p;
      }
      if (p == last) return false;
      last = p;    
      n -= cur;
    }
    return true;
  }
};
