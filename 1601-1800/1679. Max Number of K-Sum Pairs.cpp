// https://zxi.mytechroad.com/blog/hashtable/leetcode-1679-max-number-of-k-sum-pairs/
class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int ans = 0;
    for (int x : nums) ++m[x];
    for (int x : nums) {      
      if (m[x] < 1 || m[k - x] < 1 + (x + x == k)) continue;
      --m[x];
      --m[k - x];
      ++ans;      
    }
    return ans;
  }
};
