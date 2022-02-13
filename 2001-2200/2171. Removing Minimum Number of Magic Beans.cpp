// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1766764/C%2B%2BJavaPython3-Sorting-4-lines
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long res = LLONG_MAX;
        const long long n = beans.size();
        long long sum = accumulate(beans.begin(), beans.end(), 0L);
        for(long long i = 0; i < n; ++i) {
            long long left = (n - i);
            long long totalLeft = left * beans[i];
            res = min(res, sum - totalLeft);
        }
        
        return res;
    }
};
