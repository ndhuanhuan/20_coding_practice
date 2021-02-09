
class Solution {
public:
  int sumOfUnique(vector<int>& nums) {
    vector<int> seen(101);
    int ans = 0;
    for (int x : nums)
      ++seen[x];
    for (int x : nums)
      if (seen[x] == 1) ans += x;
    return ans;
  }
};
