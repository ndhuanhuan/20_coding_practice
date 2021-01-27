// https://leetcode.com/problems/decode-xored-permutation/discuss/1031107/JavaC%2B%2BPython-Straight-Forward-Solution
class Solution {
public:
    vector<int> decode(vector<int>& A) {
        int n = A.size() + 1, a = 0;
        
        // a is a1, compute a1
        // a1 = 1^2^3...^n^a2^a2^a3...^an
        for (int i = 0; i <= n; ++i) {
            a ^= i;
            if (i < n && i % 2 == 1) {
                a ^= A[i];
            }
        }
        vector<int> res = {a};
        for (int a: A) {
            res.push_back(res.back() ^ a);
        }
        return res;
    }
};
