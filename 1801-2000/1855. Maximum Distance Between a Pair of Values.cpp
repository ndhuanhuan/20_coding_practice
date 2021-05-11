// https://zxi.mytechroad.com/blog/two-pointers/leetcode-1855-maximum-distance-between-a-pair-of-values/
class Solution {
public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {    
    int ans = 0;
    for (int i = 0, j = -1; i < nums1.size(); ++i) {
      while (j + 1 < nums2.size() && nums2[j + 1] >= nums1[i]) ++j;
      if (j >= i) ans = max(ans, j - i);
    }
    return ans;
  }
};
