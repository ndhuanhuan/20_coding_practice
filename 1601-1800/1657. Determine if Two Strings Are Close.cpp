// https://zxi.mytechroad.com/blog/hashtable/leetcode-1657-determine-if-two-strings-are-close/
class Solution {
public:
  bool closeStrings(string word1, string word2) {
    const int l1 = word1.length();
    const int l2 = word2.length();
    if (l1 != l2) return false;
    vector<int> f1(128), f2(128);
    vector<int> s1(128), s2(128);
    for (char c: word1) ++f1[c], s1[c] = 1;
    for (char c: word2) ++f2[c], s2[c] = 1;
    sort(begin(f1), end(f1));
    sort(begin(f2), end(f2));
    return f1 == f2 && s1 == s2;
  }
};
