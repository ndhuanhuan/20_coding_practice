// https://leetcode.com/problems/jump-game-vii/discuss/1224804/JavaC%2B%2BPython-One-Pass-DP
// pre is a sliding window indicates whether there's any location that can jump to current location.
class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        int n = s.size(), pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            if (i >= minJ)
                pre += dp[i - minJ]; // maintain sliding window, move window right
            if (i > maxJ)
                pre -= dp[i - maxJ - 1]; // maintain sliding window, move window right
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n - 1];
    }
};
