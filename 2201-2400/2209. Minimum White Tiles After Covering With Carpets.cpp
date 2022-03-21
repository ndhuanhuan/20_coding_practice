// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/discuss/1863955/JavaC%2B%2BPython-DP-solution
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1));
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= numCarpets; ++k) {
                int jump = dp[i - 1][k] + floor[i - 1] - '0';
                int cover = k > 0 ? dp[max(i - carpetLen, 0)][k - 1] : 1000;
                dp[i][k] = min(cover, jump);
            }
        }
        return dp[n][numCarpets];
    }
};
