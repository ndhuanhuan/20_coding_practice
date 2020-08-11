//https://zxi.mytechroad.com/blog/algorithms/array/leetcode-941-valid-mountain-array/
class Solution {
public:
  bool validMountainArray(vector<int>& A) {
    if (A.size() < 3) return false;
    bool has_up = false;
    bool has_down = false;
    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1]) {
        if (has_down) return false;
        has_up = true;
      }
      else if (A[i] < A[i - 1]){
        if (!has_up) return false;
        has_down = true;
      } else {
        return false;
      }
    }
    return has_up && has_down;
  }
};
