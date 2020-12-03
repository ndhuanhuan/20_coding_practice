

// https://zxi.mytechroad.com/blog/priority-queue/leetcode-1675-minimize-deviation-in-array/
class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    set<int> s;
    for (int x : nums)
      s.insert(x & 1 ? x * 2 : x);
    int ans = *rbegin(s) - *begin(s);
    while (*rbegin(s) % 2 == 0) {
      s.insert(*rbegin(s) / 2);
      s.erase(*rbegin(s));
      ans = min(ans, *rbegin(s) - *begin(s));
    }
    return ans;
  }
}
