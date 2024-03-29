// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/discuss/1635033/C%2B%2B-O(N)-time-one-pass
class Solution {
public:
    long long getDescentPeriods(vector<int>& A) {
        long long ans = 0, N = A.size();
        for (long long i = 0; i < N; ) {
            long long len = 1;
            ++i;
            while (i < N && A[i] == A[i - 1] - 1) ++i, ++len;
            ans += (1 + len) * len / 2;
        }
        return ans;
    }
};
