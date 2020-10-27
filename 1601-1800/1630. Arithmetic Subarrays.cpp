// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1630-arithmetic-subarrays/
class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ans(l.size(), true);
    for (int i = 0; i < l.size(); ++i) {
      vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
      sort(begin(arr), end(arr));
      const int d = arr[1] - arr[0];
      for (int j = 2; j < arr.size() && ans[i]; ++j)
        ans[i] = ans[i] && (arr[j] - arr[j - 1] == d);
    }
    return ans;
  }
};
