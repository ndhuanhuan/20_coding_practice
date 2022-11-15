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

// 486. Predict the Winner
class Solution {
public:
    vector<vector<int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(n, INT_MIN));
        int res = dfs(nums, 0, n -1);
        return res >= 0;
    }
    // Max diff (my_score - op_score) of subarray nums[l] ~ nums[r].
    int dfs(vector<int>& nums, int l, int r) {
        if(l > r) return 0;
        if(memo[l][r] != INT_MIN) return memo[l][r];
        
        memo[l][r] = max(nums[l] - dfs(nums, l + 1, r), nums[r] - dfs(nums, l, r - 1));
        
        return memo[l][r];
    }
};
