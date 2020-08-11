// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1191-k-concatenation-maximum-sum/
class Solution {
public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    constexpr int kMod = 1e9 + 7;
    auto maxSum = [&arr](int r) {
      long sum = 0;
      long ans = 0;
      for (int i = 0; i < r; ++i) {
        for (long a : arr) {
          sum = max(0L, sum += a);          
          ans = max(ans, sum);
        }
      }
      return ans;
    };
    if (k < 3) return maxSum(k) % kMod;
    long ans1 = maxSum(1);
    long ans2 = maxSum(2);    
    long sum = accumulate(begin(arr), end(arr), 0L);
    return max({ans1, ans2, ans2 + sum * (k - 2)}) % kMod;
  }
};
