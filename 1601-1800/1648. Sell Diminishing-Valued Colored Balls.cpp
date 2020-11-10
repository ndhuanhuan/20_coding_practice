// https://zxi.mytechroad.com/blog/greedy/leetcode-1648-sell-diminishing-valued-colored-balls/
class Solution {
public:
  int maxProfit(vector<int>& inventory, int orders) {
    constexpr int kMod = 1e9 + 7;
    const int n = inventory.size();
    sort(rbegin(inventory), rend(inventory));
    long cur = inventory[0];
    long ans = 0;
    int c = 0;
    while (orders) { 
      // use 5, 5, 5, 2, 1 as example
      // c is how many balls have same color, here there are 5, 5, 5, so c is 3
      while (c < n && inventory[c] == cur) ++c;
      // nex is the next number which does not include in calculation, here is 2
      int nxt = c == n ? 0 : inventory[c];
      // count how many balls we will purchase
      int count = min(static_cast<long>(orders), c * (cur - nxt));
      // a trick for calculate "mo xiang"
      int t = cur - nxt;
      int r = 0;
      // edge case, not enough orders
      if (orders < c * (cur - nxt)) {
        t = orders / c;
        r = orders % c;
      }
    // (shou xiang + mo xiang) * xiang shu / 2  * how many colors have same number
    // +1 because (5 + 3)  which is (5 + 2 + 1)
      ans = (ans + (cur + cur - t + 1) * t / 2 * c + (cur - t) * r) % kMod;
      orders -= count;
      cur = nxt;
    }
    return ans;
  }
};
