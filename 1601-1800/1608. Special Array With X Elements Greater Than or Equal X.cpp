// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1608-special-array-with-x-elements-greater-than-or-equal-x/
class Solution {
public:
  int specialArray(vector<int>& nums) {
    const int n = nums.size();
    vector<int> f(n + 2);
    for (int v : nums) ++f[min(v, n)];
    for (int i = n; i >= 0; --i)
      if ((f[i] += f[i + 1]) == i) return i;
    return -1;
  }
};
