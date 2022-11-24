// 509. Fibonacci Number
class Solution {
public:
    int fib(int N) {
        if(N < 2) return N;
        vector<int> dp(N+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i-1] + dp[i - 2];
        }
        
        return dp[N];
    }
};

// 91. Decode Ways

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

// 91. Decode Ways gucheng version
class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        if(n == 0) return 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; ++i) {
            if (isValid(s[i-1])) dp[i] = dp[i-1];
            if (isValid(s[i-2], s[i-1])) dp[i] += dp[i-2];
        }
        
        return dp[n];
    }
private:
    bool isValid(const char c) { return c != '0'; }
    bool isValid(const char c1, const char c2) { 
        const int num = (c1 - '0')*10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};

// 139. Word Break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, dict);
    }
    
    bool helper(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s];
        if(dict.count(s)) {
            m[s] = true;
            return true;
        }
        
        for(int i = 1; i < s.size(); ++i) {
            const string left = s.substr(0, i);
            const string right = s.substr(i);
            
            if(dict.count(right) && helper(left, dict))
                return m[s]=true;
        }
        return m[s]=false;
    }

private:
    unordered_map<string, bool> m;
};
