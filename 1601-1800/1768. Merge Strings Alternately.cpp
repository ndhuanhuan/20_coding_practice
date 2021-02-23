// https://zxi.mytechroad.com/blog/uncategorized/leetcode-1768-merge-strings-alternately/
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    const int l1 = word1.size(), l2 = word2.size();
    string ans;
    for (int i = 0; i < min(l1, l2); ++i) {
      ans += word1[i]; 
      ans += word2[i];
    }
    ans += l1 > l2 ? word1.substr(l2) : word2.substr(l1);    
    return ans;
  }
};
