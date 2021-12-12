// https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624222/JavaC%2B%2BPython-O(n)-solution-detailed-explanation
class Solution {
public:
    long long subArrayRanges(vector<int>& A) {
        long long res = 0;
        for (int i = 0; i < A.size(); i++) {
            int ma = A[i], mi = A[i];
            for (int j = i; j < A.size(); j++) {
                ma = max(ma, A[j]);
                mi = min(mi, A[j]);
                res += ma - mi;
            }
        }
        return res;
    }
};
