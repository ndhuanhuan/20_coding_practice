// Steps to reach room i-1 for the first time, which is steps[i-1]
// 1 step to go to nextVisit[i-1]
// Steps to reach room i-1 for the second time, which is steps[i-1] - steps[nextVisit[i-1]], since this time we start from room nextVisit[i-1] instead of room 0
// 1 step to finally move to room i
// https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/discuss/1445225/Python-short-dp-explained
// https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/discuss/1445156/C%2B%2B-DP
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i < N; ++i) {
            dp[i] = ((long)2 + 2 * dp[i - 1] - dp[A[i - 1]] + mod) % mod;
        }
        return dp[N - 1];
    }
};
