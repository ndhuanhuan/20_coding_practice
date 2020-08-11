// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1535-find-the-winner-of-an-array-game/
class Solution {
public:
  int getWinner(vector<int>& arr, int k) {
    int winner = arr[0];
    int win = 0;
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] > winner) {
        winner = arr[i];
        win = 0;
      }
      if (++win == k) break;
    }
    return winner;
  }
};
