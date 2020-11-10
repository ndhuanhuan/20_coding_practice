// https://zxi.mytechroad.com/blog/simulation/1646-get-maximum-in-generated-array/
class Solution {
public:
  int getMaximumGenerated(int n) {
    vector<int> nums(n + 1);
    nums[0] = 0;
    if (n > 0) nums[1] = 1;
    for (int i = 1; i * 2 <= n; ++i) {
      nums[2 * i] = nums[i];
      if (i * 2 + 1 <= n) nums[2 * i + 1] = nums[i] + nums[i + 1];
    }
    return *max_element(begin(nums), end(nums));
  }
};
