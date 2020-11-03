// https://leetcode.com/problems/kth-smallest-instructions/discuss/918396/Python-Math-solution-Introduction-to-Combinatorics
// https://leetcode.com/problems/kth-smallest-instructions/discuss/918375/C%2B%2B-Combination
// 排除法
// [
//   "HHHVV",
//   "HHVHV",
//   "HHVVH",
//   "HVHHV",
//   "HVHVH",
//   "HVVHH",
//   "VHHHV",
//   "VHHVH",
//   "VHVHH",
//   "VVHHH"
// ]
// 比如我们求k=3 排列
// 如果第一个是字母是“H”，我们可以知道一共还剩C(2 + 2, 2) = 6 种排列
// 如果第2个是字母是“H”, prefix is "HH"，我们可以知道一共还剩C(2 + 1, 2) = 3 种排列
// 如果第3个是字母是“H”, prefix is "HHH"，我们可以知道一共还剩C(2 + 1, 2) = 1 种排列, 此时已经不对，因为无论如何也得不到第k个解
// 我们可以得知第三个字母是 "V", 同时我们可以排除掉C(2 + 1, 2) = 1 lexicon order小于当前“HHV” prefix的解， 所以code里会k -= c


class Solution {
    int comb(int n, int r) {
        long ans = 1;
        for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) ans = ans * j / i;
        return ans;
    }
public:
    string kthSmallestPath(vector<int>& A, int k) {
        int h = A[1], v = A[0], N = h + v;
        string s;
        for (int i = 0; i < N; ++i) {
            if (h) { // we have H available to pick
                int c = comb(h - 1 + v, v); // if we pick H at the current position, there will be `c` combinations for the rest of characters
                cout << h << " " << v << " " << c << endl;
                if (k <= c) { // k is covered within `c`, so we should pick H.
                    s += 'H';
                    --h;
                } else { // otherwise we should pick V
                    k -= c;
                    s += 'V';
                    --v;
                }
            } else { // no H left, have to pick V.
                s += 'V';
                --v;
            }
        }
        return s;
    }
};
