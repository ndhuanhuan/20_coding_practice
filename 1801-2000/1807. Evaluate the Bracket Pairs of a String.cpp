// https://zxi.mytechroad.com/blog/hashtable/leetcode-1807-evaluate-the-bracket-pairs-of-a-string/
class Solution {
public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> m;
    for (const auto& p : knowledge)
      m[p[0]] = p[1];
    string ans;
    string cur;
    bool in = false;
    for (char c : s) {
      if (c == '(') {
        in = true;       
      } else if (c == ')') {
        if (m.count(cur))
          ans += m[cur];
        else
          ans += "?";
        cur.clear();
        in = false;      
      } else {
        if (!in) ans += c;
        else cur += c;
      }
    }
    return ans;
  }
};
