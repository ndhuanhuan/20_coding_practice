// https://leetcode.com/problems/time-needed-to-buy-tickets/discuss/1576932/C%2B%2B-One-Pass
class Solution {
public:
    int timeRequiredToBuy(vector<int>& A, int k) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            ans += min(A[k] - (i > k), A[i]);
        }
        return ans;
    }
};
