// https://zxi.mytechroad.com/blog/algorithms/array/leetcode1732-find-the-highest-altitude/
class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    const int m = languages.size();
    vector<unordered_set<int>> langs;
    for (auto& l : languages) {
      sort(begin(l), end(l));
      langs.emplace_back(begin(l), end(l));
    }
    for (auto& e : friendships) {
      const auto& l0 = languages[--e[0]];
      const auto& l1 = languages[--e[1]];
      vector<int> common;
      set_intersection(begin(l0), end(l0), begin(l1), end(l1), back_inserter(common));
      if (common.size()) e[0] = e[1] = -1;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
      vector<int> users(m);
      for (const auto& e : friendships) {
         // e[0] and e[1] have a common language, skip this edge
        if (e[0] == -1) continue;
        if (!langs[e[0]].count(i)) users[e[0]] = 1;
        if (!langs[e[1]].count(i)) users[e[1]] = 1;
      }
      ans = min(ans, accumulate(begin(users), end(users), 0));      
    }
    return ans;
  }
};
