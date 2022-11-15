// 292. Nim Game
class Solution {
public:
    bool canWinNim(int n) {
        vector<bool> dp(max(n+1, 4));
        
        dp[1] = dp[2] = dp[3] = true;
        
        for(int i = 4; i <= n; ++i) {
            dp[i] = !dp[i-1] || !dp[i-2] || !dp[i-3];
        }
        
        return dp[n];
    }
};
