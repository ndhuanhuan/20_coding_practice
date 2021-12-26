// https://leetcode.com/problems/intervals-between-identical-elements/discuss/1647499/Hash-and-Formula
// https://zxi.mytechroad.com/blog/hashtable/leetcode-2121-intervals-between-identical-elements/
class Solution {
public:
  vector<long long> getDistances(vector<int>& arr) {
    const int n = arr.size();
    unordered_map<int, vector<long long>> m;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      m[arr[i]].push_back(i); // key: unique value, value: list of indices
      pos[i] = m[arr[i]].size() - 1; // key: index of number, value: index in unordered_map
    }
    for (auto& [k, idx] : m) {
        // cout << k << endl;
        // cout << idx.size() << endl;
        partial_sum(begin(idx), end(idx), begin(idx));    // https://www.cplusplus.com/reference/numeric/partial_sum/
    }
           
    vector<long long> ans(n);
    for (int i = 0; i < n; ++i) {
      const auto& sums = m[arr[i]];
      const long long k = pos[i];
      const long long c = sums.size();      
      if (k > 0) ans[i] += k * i - sums[k - 1];
      if (k + 1 < c) ans[i] += (sums[c - 1] - sums[k]) - (c - k - 1) * i;
    }
    return ans;
  }
};
