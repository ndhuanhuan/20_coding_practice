class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<int> finalLocations;
        const int MOD = 1000000007;
        
        const int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'R') {
                finalLocations.push_back(nums[i] + d);
            } else {
                finalLocations.push_back(nums[i] - d);
            }
        }
        
        vector<long long> prefixSum;
        
        sort(finalLocations.begin(), finalLocations.end());
        prefixSum.push_back(finalLocations[0]);
        
        long long res = 0;
        
        for (int i = 1; i < finalLocations.size(); ++i) {
            long long dist = ((long long)finalLocations[i] * i - (long long)prefixSum.back()) % MOD;
            res = (res + dist) % MOD;
            long long sum = prefixSum.back() + finalLocations[i];
            prefixSum.push_back(sum);
        }
        
        return res;
    }
};
