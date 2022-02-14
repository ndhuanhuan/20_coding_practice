// https://leetcode.com/problems/maximum-and-sum-of-array/discuss/1766743/C%2B%2B-Short-Bitmask-DP
// use 2 bits to represent one slot. Since one slot can store 2 numbers. 
// Trick: how to decide which slot, read the post
class Solution {
public:
    int maximumANDSum(vector<int>& A, int s) {
        while (A.size() < 2 * s) A.push_back(0); // pad 0s
        int N = A.size();
        vector<int> dp(1 << N);
        for (int m = 1; m < 1 << N; ++m) {
            int cnt = __builtin_popcount(m), slot = (cnt + 1) / 2;
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) {
                    dp[m] = max(dp[m], dp[m ^ (1 << i)] + (slot & A[i]));
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};
