class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        const int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        long long res = INT_MIN;
        
        for(int i = 0; i < n ; ++i) {
            long long left = prefix[i];
            long long right = prefix[n-1] - (i == 0 ? 0 : prefix[i-1]);
            res = max(res, max(left, right));
        }
        
        return res;
    }
};
