// https://zxi.mytechroad.com/blog/math/leetcode-1689-partitioning-into-minimum-number-of-deci-binary-numbers/
class Solution {
public:
  int minPartitions(string n) {
    return *max_element(begin(n), end(n)) - '0';
  }
};
