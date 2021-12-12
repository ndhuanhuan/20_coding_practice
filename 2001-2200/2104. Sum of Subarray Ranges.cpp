// https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624222/JavaC%2B%2BPython-O(n)-solution-detailed-explanation
// https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624268/Reformulate-Problem-O(n)
long long subArrayRanges(vector<int>& n) {
    return sumSubarrayComp(n, less<int>()) - sumSubarrayComp(n, greater<int>());
}    
long long sumSubarrayComp(vector<int>& n, function<bool (int, int)> comp) {
    long long res = 0;
    vector<int> s;
    for (int i = 0; i <= n.size(); ++i) {
        while (!s.empty() && (i == n.size() || comp(n[s.back()], n[i]))) {
            int j = s.back(), k = s.size() < 2 ? -1 : s[s.size() - 2]; 
            res += (long long)(i - j) * (j - k) * n[j];
            s.pop_back();
        }
        s.push_back(i);
    }    
    return res;
}


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
