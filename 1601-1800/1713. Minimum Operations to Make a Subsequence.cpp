// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1713-minimum-operations-to-make-a-subsequence/
class Solution {
public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> m;
    for (int i = 0; i < target.size(); ++i)
      m[target[i]] = i;
    vector<int> s;
    for (int a : arr) {
      auto mit = m.find(a);
      if (mit == end(m)) continue;
      const int idx = mit->second;
      auto it = lower_bound(begin(s), end(s), idx);
      if (it == end(s))
        s.push_back(idx);
      else
        *it = idx;
    }
    return target.size() - s.size();
  }
};
