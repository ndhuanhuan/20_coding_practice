// https://zxi.mytechroad.com/blog/math/leetcode-1808-maximize-number-of-nice-divisors/
// https://leetcode.com/problems/maximize-number-of-nice-divisors/discuss/1130512/Break-primeFactors-into-integers-to-maximize-products-or-Simple-solution-w-Explanation-O(logn)
class Solution {
public:
  int maxNiceDivisors(int n) {
    constexpr int kMod = 1e9 + 7;
    auto powm = [](long base, int exp) {
      long ans = 1;
      while (exp) {
        if (exp & 1) ans = (ans * base) % kMod;
        base = (base * base) % kMod;
        exp >>= 1;
      }
      return ans;
    };
    
    if (n <= 3) return n;
    switch (n % 3) {
      case 0: return powm(3, n / 3);
      case 1: return (powm(3, n / 3 - 1) * 4) % kMod;
      case 2: return (powm(3, n / 3) * 2) % kMod;
    }
    return -1;
  }
};
