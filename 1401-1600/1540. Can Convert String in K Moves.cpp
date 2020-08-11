// https://zxi.mytechroad.com/blog/hashtable/leetcode-1540-can-convert-string-in-k-moves/
class Solution {
public:
  bool canConvertString(string s, string t, int k) {
    if (s.length() != t.length()) return false;
    vector<int> count(26);    
    for (int i = 0; i < s.length(); ++i) {            
      int d = (t[i] - s[i] + 26) % 26;
      int c = count[d]++;
      if (d != 0 && d + c * 26 > k)
        return false;
    }    
    return true;
  }
};
