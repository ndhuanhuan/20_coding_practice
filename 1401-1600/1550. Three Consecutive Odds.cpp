// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1550-three-consecutive-odds/
class Solution {
public:
  bool threeConsecutiveOdds(vector<int>& arr) {       
    int count = 0;
    for (int x : arr) {
      if (x & 1) {
        if (++count == 3) return true;
      } else {
        count = 0;
      }
    }
    return false;      
  }
};
