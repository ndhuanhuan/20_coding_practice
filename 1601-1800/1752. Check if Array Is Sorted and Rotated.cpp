// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1752-check-if-array-is-sorted-and-rotated/
class Solution {
public:
  bool check(vector<int>& nums) {
    int count = 0;
    int r = -1;
    for (size_t i = 1; i < nums.size(); ++i)
      if (nums[i] < nums[i - 1]) {
        ++count;
        r = i;
      }
    if (count == 0) return true;
    if (count > 1) return false;     
    return nums[r] <= nums[0] && nums[r - 1] >= nums.back();
  }
};
