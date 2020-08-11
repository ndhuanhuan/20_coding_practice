// https://zxi.mytechroad.com/blog/math/leetcode-1344-angle-between-hands-of-a-clock/
class Solution {
public:
  double angleClock(int hour, int minutes) {
    double a_m = minutes * 360 / 60;
    double a_h = (hour + minutes / 60.0) * 360 / 12;
    return min(abs(a_m - a_h), 360 - abs(a_m - a_h));
  }
};
