// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1653-minimum-deletions-to-make-string-balanced/
// dp[i][0] := min # of dels to make s[0:i] all ‘a’s;
// dp[i][1] := min # of dels to make s[0:i] ends with 0 or more ‘b’s

// if s[i-1] == ‘a’:
// dp[i + 1][0] = dp[i][0], dp[i + 1][1] = min(dp[i + 1][0], dp[i][1] + 1)
// else:
// dp[i + 1][0] = dp[i][0] + 1, dp[i + 1][1] = dp[i][1]

class Solution {
public:
    int minimumDeletions(string s) {
        const int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'a') {
                dp[i+1][0] = dp[i][0];
                dp[i+1][1] = min(dp[i+1][0], dp[i][1] + 1);
            } else {
                dp[i + 1][0] = dp[i][0] + 1;
                dp[i + 1][1] = dp[i][1];
            }
        }
        return min(dp[n][0], dp[n][1]);
    }
};
