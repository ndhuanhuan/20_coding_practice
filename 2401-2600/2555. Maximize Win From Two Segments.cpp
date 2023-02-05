// https://leetcode.com/problems/maximize-win-from-two-segments/discuss/3141449/JavaC%2B%2BPython-DP-%2B-Sliding-Segment-O(n)
class Solution {
public:
      int maximizeWin(vector<int>& A, int k) {
        int res = 0, n = A.size(), j = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            while (A[j] < A[i] - k)
                ++j;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1 + dp[j]);
        }
        return res;
    }
};
