// https://zxi.mytechroad.com/blog/bit/leetcode-1558-minimum-numbers-of-function-calls-to-make-target-array/
class Solution {
public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    int high = 0;
    for (int x : nums) {
      high = max(high, 31 - __builtin_clz(x | 1));
      ans += std::bitset<32>(x).count();
    }
    return ans + high;
  }
};
