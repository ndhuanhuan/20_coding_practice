// https://leetcode.com/problems/maximum-earnings-from-taxi/discuss/1470935/C%2B%2BPython-DP-O(M%2BN)-Clean-and-Concise
#define pii pair<int, int>
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pii>> rideStartAt(n);
        for (auto& ride : rides) {
            int s = ride[0], e = ride[1], t = ride[2];
            rideStartAt[s].push_back({e, e - s + t});  // [end, dollar]
        }
        vector<long long> dp(n+1);
        for (int i = n-1; i >= 1; --i) {
            for (auto& [e, d] : rideStartAt[i]) {
                dp[i] = max(dp[i], dp[e] + d);
            }
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[1];
    }
};
