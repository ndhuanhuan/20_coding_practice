// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1553-minimum-number-of-days-to-eat-n-oranges/
class Solution {
public:
  int minDays(int n) {
    unordered_map<int, int> cache;
    function<int(int)> dp = [&](int n) {
      if (n <= 1) return n;
      auto it = cache.find(n);
      if (it != cache.end()) return it->second;
      return cache[n] = 1 + min(n % 2 + dp(n / 2), n % 3 + dp(n / 3));
    };
    return dp(n);
  }
};
