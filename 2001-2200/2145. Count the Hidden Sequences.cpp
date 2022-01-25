class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        const int n = differences.size();
        
        long long cur = 0, curMax = 0, curMin = 0;
        for(int i = 0; i < n; ++i) {
            cur += differences[i];
            curMax = max(cur, curMax);
            curMin = min(cur, curMin);
        }
        
        long long lowerBound = lower - curMin;
        long long upperBound = upper - curMax;
        
        long long res = upperBound - lowerBound + 1;
        
        return res >= 0 ? res : 0;
    }
};
