// https://zxi.mytechroad.com/blog/math/leetcode-1551-minimum-operations-to-make-array-equal/
class Solution {
public:
  int minOperations(int n) {    
    return (n / 2) * ((n + 1) / 2);
  }
};
