// https://leetcode.cn/problems/sum-of-k-subarrays-with-length-at-least-m/solutions/3591733/hua-fen-xing-dp-qian-zhui-he-shi-zi-bian-3k0w/
class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<int> s(n + 1), f(n + 1), d(n + 1);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1); // 前缀和

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= n; j++) {
                d[j] = f[j] - s[j];
            }
            // f[j] 置为 -inf，因为即使 [0,j) 全选，也没有 i 个长为 m 的子数组
            fill(f.begin() + (i * m - m), f.begin() + (i * m), INT_MIN / 2);
            int mx = INT_MIN;
            // 左右两边留出足够空间给其他子数组
            for (int j = i * m; j <= n - (k - i) * m; j++) {
                // mx 表示最大的 f[L]-s[L]，其中 L 在区间 [(i-1)*m, j-m] 中
                mx = max(mx, d[j - m]);
                f[j] = max(f[j - 1], mx + s[j]); // 不选 vs 选
            }
        }
        return f[n];
    }
};
