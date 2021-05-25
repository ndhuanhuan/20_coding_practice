// https://leetcode.com/problems/stone-game-viii/discuss/1224640/C%2B%2BPython-DP-O(N)-time-O(1)-space-(2-lines-1-line)
class Solution {
public:
    int stoneGameVIII(vector<int>& A) {
        int N = A.size();
        for (int i = 1; i < N; ++i) A[i] += A[i - 1]; // now A[i] is the prefix sum, i.e. prefix[i]
		int dp = A.back(); // dp[N - 2] = prefix[N - 1]
        for (int i = N - 2; i > 0; --i) dp = max(dp, A[i] - dp); // dp[i - 1] = max(dp[i], A[i] - dp[i]) 
        return dp; // dp[0]
    }
};
