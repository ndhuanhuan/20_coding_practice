// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1764-form-array-by-concatenating-subarrays-of-another-array/
class Solution {
public:
  bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
    const int n = nums.size();
    int s = 0;
    for (const auto& g : groups) {
      bool found = false;
      for (int i = s; i <= n - g.size(); ++i)
        if (equal(begin(g), end(g), begin(nums) + i)) {
          s = i + g.size();
          found = true;
          break;
        }
      if (!found) return false;
    }
    return true;
  }
};
