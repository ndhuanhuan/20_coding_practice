// https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii/solutions/2826591/deng-jie-zhuan-huan-dong-tai-gui-hua-pyt-z2fs/
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector<vector<int>> f(k, vector<int>(k));
        for (int x : nums) {
            x %= k;
            for (int y = 0; y < k; y++) {
                f[y][x] = f[x][y] + 1;
                ans = max(ans, f[y][x]);
            }
        }
        return ans;
    }
};

