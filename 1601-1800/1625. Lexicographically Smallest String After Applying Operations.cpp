// https://zxi.mytechroad.com/blog/searching/leetcode-1625-lexicographically-smallest-string-after-applying-operations/
class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> seen;    
    string ans(s);
    function<void(string)> dfs = [&](const string& s) {
      if (!seen.insert(s).second) return;
      ans = min(ans, s);
      string t(s);
      for (int i = 1; i < s.length(); i += 2)
        t[i] = (t[i] - '0' + a) % 10 + '0';
      dfs(t);
      dfs(s.substr(b) + s.substr(0, b));
    };    
    dfs(s);
    return ans;
  }
};
