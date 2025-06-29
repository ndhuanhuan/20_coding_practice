// https://leetcode.cn/problems/partition-array-to-minimize-xor/solutions/3710966/hua-fen-xing-dp-de-tong-yong-tao-lu-pyth-lmcm/
class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector f(k + 1, vector<int>(n + 1, INT_MAX));
        f[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            // 前后每个子数组长度至少是 1，预留空间给这些子数组
            for (int j = i; j <= n - (k - i); j++) {
                int s = 0;
                // 枚举所有分割方案，取最小值
                for (int l = j - 1; l >= i - 1; l--) {
                    s ^= nums[l];
                    // 对于单个分割方案，子数组异或和需要取最大值
                    f[i][j] = min(f[i][j], max(f[i - 1][l], s));
                }
            }
        }
        return f[k][n];
    }
};
