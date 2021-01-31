// https://zxi.mytechroad.com/blog/hashtable/leetcode-1742-maximum-number-of-balls-in-a-box/
class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    vector<int> balls(46);
    int ans = 0;
    for (int i = lowLimit; i <= highLimit; ++i) {
      int n = i;
      int box = 0;
      while (n) { box += n % 10; n /= 10; }
      ans = max(ans, ++balls[box]);
    }
    return ans;
  }
};
