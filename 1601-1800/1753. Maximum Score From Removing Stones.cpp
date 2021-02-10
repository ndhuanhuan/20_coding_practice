// https://zxi.mytechroad.com/blog/greedy/leetcode-1753-maximum-score-from-removing-stones/

class Solution {
public:
  int maximumScore(int a, int b, int c) {
    array<int, 3> s{a,b,c};
    sort(begin(s), end(s));
    int ans = 0;
    while (s[1]-- && s[2]--) {      
      ++ans;
      sort(begin(s), end(s));
    }
    return ans;
  }
};
