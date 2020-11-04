
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1639-number-of-ways-to-form-a-target-string-given-a-dictionary/
class Solution {
public:
  int numWays(vector<string>& words, string target) {
    constexpr int kMod = 1e9 + 7;
    const int n = target.length();
    const int m = words[0].length();
    
    vector<long> dp(n); // dp[j] = # of ways to form t[0~j]
    for (int i = 0; i < m; ++i) {
      vector<int> count(26);
      for (const string& word: words)
        ++count[word[i] - 'a'];      
      for (int j = min(i, n - 1); j >= 0; --j)
        dp[j] = (dp[j] + (j > 0 ? dp[j - 1] : 1) * 
                    count[target[j] - 'a']) % kMod;
    }
    return dp[n - 1];
  }
};
