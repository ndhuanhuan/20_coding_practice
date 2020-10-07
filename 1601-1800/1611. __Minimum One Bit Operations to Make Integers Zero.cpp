// https://zxi.mytechroad.com/blog/math/leetcode-1611-minimum-one-bit-operations-to-make-integers-zero/
// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/discuss/877809/GreyCode-to-decimal-C%2B%2B-Math-solution
class Solution {
public:
  int minimumOneBitOperations(int n) {
    int ans = 0;
    while (n) {
      ans ^= n;
      n >>= 1;
    }
    return ans;
  }
};
