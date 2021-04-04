// https://zxi.mytechroad.com/blog/hashtable/leetcode-1814-count-nice-pairs-in-an-array/
class Solution {
public:
  int countNicePairs(vector<int>& nums) {
    constexpr int kMod = 1e9 + 7;
    unordered_map<int, int> m;
    long ans = 0;
    for (int x : nums) {      
      string s = to_string(x);
      reverse(begin(s), end(s));
      ans += m[x - stoi(s)]++;
    }
    return ans % kMod;
  }
};
