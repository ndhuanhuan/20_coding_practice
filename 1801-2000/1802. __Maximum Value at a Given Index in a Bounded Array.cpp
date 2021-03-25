// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/discuss/1119708/C%2B%2B-Binary-Search-O(log-n)
class Solution {
public:
  int maxValue(int n, int i, int maxSum) {
        int l = 0, r = maxSum, j = n - i - 1;
        while (l < r) {
            long m = (l + r + 1) / 2;
            auto need = m * m - ((m > i ? (m - i - 1) * (m - i) : 0)  // there are i elements on the left, if there's not enough elements on the left, we cannot construct sequence like [ ..., x-2, x-1, x, ...]
                + (m > j ? (m - j - 1) * (m - j) : 0)) / 2;           // j elements on the right, if there's not enough elements on the right, we cannot construct sequence like [ ..., x, x-1, x-2]
            if (need <= maxSum - n)
                l = m;
            else
                r = m - 1;
        }
        return l + 1;
    }
};
