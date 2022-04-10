// https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/discuss/1931085/Explanation-with-pictures-Greedy.
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const int n = flowers.size();
        int minFlower = INT_MAX;
        long long sum = 0;
        for(int i = 0; i < flowers.size(); ++i) {
            flowers[i] = min(flowers[i], target);
            minFlower = min(minFlower, flowers[i]);
            sum += flowers[i];
        }
        
        sort(flowers.begin(), flowers.end());
        
        // 2 edge cases
        
        if(minFlower == target) {
            return (long long)full * n;
        }
        
        if(newFlowers >= (long long)target * n - sum) {
            return max((long long)full * n, ((long long)full* (n-1) + (long long)partial * (target-1)));
        }
        
        vector<long long> cost(n, 0);
        for(int i = 1; i < n; ++i) {
            long long pre = cost[i-1];
            cost[i] = (long long)pre + (long long)i * (flowers[i] - flowers[i-1]);
        }
        
        int j = n -1;
        while(flowers[j] == target) {
            --j;
        }
        
        long long res = 0;
        
        while(newFlowers >= 0) {
            auto upper = upper_bound(cost.begin(), cost.end(), newFlowers);
            int idx = (upper-cost.begin()) - 1;
            idx = min(j, idx);
            
            int bar = flowers[idx] + (newFlowers-cost[idx]) / (idx + 1);
            
            res = max(res, (long long)bar * (long long)partial + (long long)full * (long long)(n - j - 1));
            
            newFlowers -= (target - flowers[j]);
            --j;
        }
        
        return res;
    }
};
