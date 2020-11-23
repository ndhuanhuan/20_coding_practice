// https://zxi.mytechroad.com/blog/string/leetcode-1662-check-if-two-string-arrays-are-equivalent/
class Solution {
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string s1, s2;
    for (const string& w1 : word1) s1 += w1;
    for (const string& w2 : word2) s2 += w2;
    return s1 == s2;
  }
};
