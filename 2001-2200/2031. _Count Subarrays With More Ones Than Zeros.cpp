// https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/discuss/1512961/BIT-vs.-O(n)
// https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/discuss/1510284/C%2B%2BJavaPython-Clean-Fenwick-tree
class FenwickTree {
 public:
  FenwickTree(int n) : n(n), sums(2 * n + 1) {}

  void update(int i, int delta) {
    i += n + 1;  // re-mapping, since number can be negative
    while (i < sums.size()) {
      sums[i] += delta;
      i += i & -i;
    }
  }

  int get(int i) {
    i += n + 1;  // re-mapping, since number can be negative
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= i & -i;
    }
    return sum;
  }

 private:
  const int n;
  vector<int> sums;
};

class Solution {
 public:
  int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
    constexpr int kMod = 1e9 + 7;

    int ans = 0;
    int prefix = 0;
    FenwickTree tree(nums.size());
    tree.update(0, 1);

    for (const int num : nums) {
      prefix += num == 0 ? -1 : 1;
      ans += tree.get(prefix - 1);
      ans %= kMod;
      tree.update(prefix, 1);
    }

    return ans;
  }
};

