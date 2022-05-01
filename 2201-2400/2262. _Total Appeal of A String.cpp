// https://leetcode.com/problems/total-appeal-of-a-string/discuss/1996300/Python3-or-O(N)-O(1)-or-detail-for-beginners
class Solution {
public:
    long long appealSum(string s) {
        const long long n = s.size();
        
        vector<int> ref(26, 0);
        long long prev = 0, total = 0;
        for(long long i = 0; i < n; ++i) {
            int curAlpha = s[i] - 'a';
            
            long long addOn = i + 1;
            int dupCount = ref[curAlpha];
            
            // prev + addOn means, since we already calculate last round scores, we are only add last round score by 1
            // it is dynamical programming kind of thing, you can use previously calculated score to add 1.
            // prev + addOn equal to scores of all subarray ending at current char => important: it is only current round, not score 
            // of all existing subarray
            
            // - dupCount  and you also need to deduct those subarray already contain this number
            
            long long curTotal = prev + addOn - dupCount;
            
            total += curTotal;
            
            
            prev = curTotal;

            ref[curAlpha] = i + 1;
        }
        
        return total;
    }
};



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
