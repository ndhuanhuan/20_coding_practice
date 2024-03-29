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


// 1140. Stone Game II
class Solution {
public:
    int n;
    int helper(vector<int>& piles,vector<vector<int>>& memo,vector<int>& sum, int start, int M){
        if(start == n-1) return piles[start];
        if(memo[start][M] != -1) return memo[start][M];
        
        //if M> number of piles left, take the suffix sum directly
        if(n-start<= 2*M) return sum[start];
        
        int ans =INT_MAX;
        //can take minimum 1, maximum 2M piles
        for(int i=1;i<=2*M;i++){
            //to minimize opponent's choice
            ans =min(ans, helper(piles,memo,sum,start+i,max(M,i)));
        }
        
        //result is (sum - opponent's score)
         return memo[start][M] =sum[start] - ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        
        //calculate suffix sum        
        vector<int> sum(n);
        sum[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--){
            sum[i] = piles[i] + sum[i+1];
        }
        
        //<start index,M>
        vector<vector<int>> memo(n,vector<int>(2*n,-1));
        return helper(piles,memo,sum,0,1);
    }
};

// 1406. Stone Game III
class Solution {
public:
    vector<int> memo;
    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        memo = vector<int>(n, INT_MIN);
        
        int score = dfs(stoneValue, 0);
        
        if(score == 0) return "Tie";
        return score > 0 ? "Alice" : "Bob";
    }
    
    int dfs(vector<int>& stoneValue, int cur) {
        if(cur == stoneValue.size()) return 0;
        if(memo[cur] != INT_MIN) return memo[cur];
        
        int res = INT_MIN;
        int score = 0;
        
        for(int i = cur; i < cur + 3 && i < (int)stoneValue.size(); ++i) {
            score += stoneValue[i];
            res = max(res, score - dfs(stoneValue, i + 1));
        }
        
        return memo[cur] = res;
    }
};

// 1510. Stone Game IV
class Solution {
public:
    vector<int> memo;
    bool winnerSquareGame(int n) {
        memo = vector<int>(n+1, -1);
        return dfs(n);
    }
    
    bool dfs(int n) {
        if(memo[n] != -1) return memo[n];
        
        for(int i = sqrt(n); i >=1; i--) {
            if(!dfs(n - i*i))
                return memo[n] = 1;
        }
        
        return memo[n] = 0;
    }
};
