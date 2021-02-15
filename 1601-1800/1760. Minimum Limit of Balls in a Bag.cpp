// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1760-minimum-limit-of-balls-in-a-bag/
class Solution {
public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1, r = *max_element(begin(nums), end(nums));
    while (l < r) {
      const int m = l + (r - l) / 2;
      int count = 0;
      for (int x : nums) 
        count += (x - 1) / m;
      if (count <= maxOperations)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
