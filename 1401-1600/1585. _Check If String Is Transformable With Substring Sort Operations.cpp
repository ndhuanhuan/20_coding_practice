// https://zxi.mytechroad.com/blog/string/leetcode-1585-check-if-string-is-transformable-with-substring-sort-operations/
class Solution {
public:
  bool isTransformable(string s, string t) {
    vector<deque<int>> idx(10);
    for (int i = 0; i < s.length(); ++i)
      idx[s[i] - '0'].push_back(i);
    for (char c : t) {
      const int d  = c - '0';
      if (idx[d].empty()) return false;
      for (int i = 0; i < d; ++i)
        if (!idx[i].empty() && idx[i].front() < idx[d].front())
          return false;
      idx[d].pop_front();      
    }
    return true;
  }
};
