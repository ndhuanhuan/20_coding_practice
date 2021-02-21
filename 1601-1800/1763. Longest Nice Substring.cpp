// https://zxi.mytechroad.com/blog/string/leetcode-1763-longest-nice-substring/
class Solution {
public:
  string longestNiceSubstring(string_view s) {    
    const int n = s.length();    
    string_view ans;
    for (int i = 0; i < n; ++i) {
      vector<int> u(26), l(26);
      for (int j = i; j < n; ++j) {
        const char c = s[j];
        if (isupper(c)) u[c - 'A'] = 1;
        else l[c - 'a'] = 1;
        if (u == l && j - i + 1 > ans.length())
          ans = s.substr(i, j - i + 1);
      }
    }
    return string(ans);
  }
};
