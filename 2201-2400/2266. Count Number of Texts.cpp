class Solution {
public:
    const int mod = 1000000007;
    int countTexts(string pressedKeys) {
        
        unordered_map<int, int> m;
        m['2'] = 3;
        m['3'] = 3;
        m['4'] = 3;
        m['5'] = 3;
        m['6'] = 3;
        m['7'] = 4;
        m['8'] = 3;
        m['9'] = 4;
        const int n = pressedKeys.size();
        if(n == 0) return 0;
        int i = 0;
        long long res = -1;
        while(i < n) {
            char cur = pressedKeys[i];
            int count = 0;
            while(i < n && pressedKeys[i] == cur) {
                ++count;
                ++i;
            }
            // cout << "here" << endl;
            // cout << count << endl;
            // cout << m[cur] << endl;
            long long tmp = helper(count, m[cur]);
            //cout << "here2";
            if(res == -1) {
                res = tmp % mod;
            } else {
                res *= tmp;
                res %= mod;
            }
        }
        
        return res;
        
    }
    
    long long helper(int n, int max) {
         //cout << "here00" << endl;   
        vector<long long> dp(n+1, 0);
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        //cout << "here3";
        if(max == 4) {
            dp[4] = dp[1] + dp[2] + dp[3] + 1;
            for(int i =5; i <= n; ++i) {
                for(int j = 1; j <= max; ++j) {
                    dp[i] += dp[i-j];
                    dp[i] %= mod;
                }
            }
        } else {
            for(int i =4; i <= n; ++i) {
                for(int j = 1; j <= max; ++j) {
                    dp[i] += dp[i-j];
                    dp[i] %= mod;
                }
            }
        }
        
        
        
        
        return dp[n];
    }
};
