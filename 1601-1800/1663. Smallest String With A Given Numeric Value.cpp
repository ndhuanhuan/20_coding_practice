// https://zxi.mytechroad.com/blog/greedy/leetcode-1663-smallest-string-with-a-given-numeric-value/
class Solution {
public:
  string getSmallestString(int n, int k) {    
    string ans(n, 'a');
    k -= n;
    while (k) {
      int d = min(k, 25);
      ans[--n] += d;
      k -= d;
    }
    return ans;
  }
};
