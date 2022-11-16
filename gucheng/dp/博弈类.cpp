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

// 1025. Divisor Game
class Solution {
public:
    
    vector<int> memo;
    bool divisorGame(int n) {
        memo = vector<int>(n+1, -1);
        return dfs(n);
    }
    
    bool dfs(int n) {
        if(n == 1) return false;
        if(memo[n] != -1) return memo[n];
        bool canWin = false;
        for(int i = 1; i <= n/2; i++) {
            if(n % i == 0 && !dfs(n-i)) {
                canWin = true;
                break;
            }
        }
        
        return memo[n] = canWin;
    }
};

// 877. Stone Game
class Solution {
public:
    vector<vector<int>> memo;
    
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        
        memo = vector<vector<int>>(n, vector<int>(n, INT_MIN));
        
        int res = dfs(piles, 0, n - 1);
        return memo[0][n-1] > 0;
    }
    
    
    int dfs(vector<int>& piles, int i, int j) {
        if(i > j) return 0;
        if(memo[i][j] != INT_MIN) return memo[i][j];
        
        memo[i][j] = max(piles[i] - dfs(piles, i+1, j), piles[j] - dfs(piles, i, j - 1));
        
        return memo[i][j];
    }
    
};
