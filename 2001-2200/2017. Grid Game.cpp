// https://leetcode.com/problems/grid-game/discuss/1486340/C%2B%2BJavaPython-Robot1-Minimize-TopSum-and-BottomSum-of-Robot-2-Picture-Explained
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(begin(grid[0]), end(grid[0]), 0ll), bottomSum = 0;
        long long ans = LLONG_MAX;
        topSum -= grid[0][0];
        ans = min(ans, max(topSum, bottomSum));
        for (int i = 1; i < grid[0].size(); ++i) {
            topSum -= grid[0][i];
            bottomSum += grid[1][i-1];
            ans = min(ans, max(topSum, bottomSum));
        }
        return ans;
    }
};
