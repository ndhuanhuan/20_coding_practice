//https://zxi.mytechroad.com/blog/hashtable/leetcode-954-array-of-doubled-pairs/
class Solution {
public:
  bool canReorderDoubled(vector<int>& A) {
    unordered_map<int, int> c;
    for (int a : A) ++c[a];
    vector<int> keys;
    for (const auto &kv : c) keys.push_back(kv.first);
    sort(begin(keys), end(keys), [](int a, int b) { return abs(a) < abs(b); });
    for (int key : keys)
      if (c[key] && (c[key * 2] -= c[key]) < 0) return false;
    return true;
  }
};
