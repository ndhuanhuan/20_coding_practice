// https://leetcode.com/problems/total-appeal-of-a-string/discuss/1996300/Python3-or-O(N)-O(1)-or-detail-for-beginners
class Solution {
public:
    long long appealSum(string s) {
        const long long n = s.size();
        
        vector<int> ref(26, 0);
        vector<long long> res(n+1, 0);
        
        for(long long i = 0; i < n; ++i) {
            int curAlpha = s[i] - 'a';
            
            res[i + 1] = res[i] + i + 1ll - ref[curAlpha];
            res[i + 1] += (i > 0) ? res[i] - res[i-1] : 0;
            
            ref[curAlpha] = i + 1;
        }
        
        return res[n];
    }
};
