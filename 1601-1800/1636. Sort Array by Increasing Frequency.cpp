// https://zxi.mytechroad.com/blog/hashtable/leetcode-1636-sort-array-by-increasing-frequency/
class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];
    sort(begin(nums), end(nums), [&](int a, int b) {
      if (freq[a] != freq[b]) return freq[a] < freq[b];
      return a > b;
    });
    return nums;
  }
};
