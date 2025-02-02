// https://leetcode.cn/problems/minimum-increments-for-target-multiples-in-an-array/solutions/3061806/zi-ji-zhuang-ya-dpji-yi-hua-sou-suo-di-t-aeaj/
class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int m = target.size();

        // 预处理 target 的所有子集的 LCM
        vector<long long> lcms(1 << m);
        lcms[0] = 1;
        for (int i = 0; i < m; i++) {
            int bit = 1 << i;
            for (int mask = 0; mask < bit; mask++) {
                lcms[bit | mask] = lcm(target[i], lcms[mask]);
            }
        }

        vector memo(n, vector<long long>(1 << m, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            if (j == 0) {
                return 0;
            }
            if (i < 0) { // 不能有剩余元素
                return LLONG_MAX / 2; // 防止溢出
            }
            long long& res = memo[i][j]; // 注意这里是引用
            if (res != -1) {
                return res;
            }
            res = dfs(i - 1, j); // 不修改 nums[i]
            for (int sub = j; sub; sub = (sub - 1) & j) { // 枚举 j 的所有非空子集
                long long l = lcms[sub];
                res = min(res, dfs(i - 1, j ^ sub) + (l - nums[i] % l) % l);
            }
            return res;
        };
        return dfs(n - 1, (1 << m) - 1);
    }
};
