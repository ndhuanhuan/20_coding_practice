
// https://zxi.mytechroad.com/blog/string/leetcode-1668-maximum-repeating-substring/
class Solution {
public:
  int maxRepeating(string sequence, string word) {
    string s(word);
    for (int i = 1;;++i) {
      if (sequence.find(s) == string::npos) return i - 1;
      s += word;
    }
    return -1;
  }
};
