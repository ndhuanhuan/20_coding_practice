class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        
        const int n = s.length();
        vector<int> dp(n, 0);
        
        dp[0] = isValid(s[0]);
        if(dp[0] == 0) return 0;
        
        for(int i = 1; i < n; ++i) {
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
            if (isValid(s[i])) dp[i] = dp[i-1];
            if (isValid(s[i-1], s[i])) dp[i] += i >= 2 ? dp[i-2] : 1;
        }
            
        return dp[n-1];
    
    }
private:
    bool isValid(const char c) { return c != '0'; }
    bool isValid(const char c1, const char c2) { 
        const int num = (c1 - '0')*10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};
