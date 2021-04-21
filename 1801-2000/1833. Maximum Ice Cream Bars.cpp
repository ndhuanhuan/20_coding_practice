class Solution {
public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(begin(costs), end(costs));
    int ans = 0;
    for (int c : costs) {
      if (c > coins) break;
      coins -= c;
      ++ans;
    }
    return ans;
  }
};
