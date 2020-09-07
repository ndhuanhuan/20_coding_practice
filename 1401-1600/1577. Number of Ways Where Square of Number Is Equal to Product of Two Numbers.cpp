// https://zxi.mytechroad.com/blog/hashtable/leetcode-1577-number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
class Solution {
public:
  int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    return solve(nums1, nums2) + solve(nums2, nums1);
  }
private:
  int solve(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;
    unordered_map<int, int> f;
    for (int y : nums2) ++f[y];
    for (long x : nums1)
      for (const auto& [y, c] : f) {                
        long r = x * x / y;
        if (x * x % y || !f.count(r)) continue;
        if (r == y) ans += c * (c - 1);
        else ans += c * f[r];
      }
    return ans / 2;
  }
};
