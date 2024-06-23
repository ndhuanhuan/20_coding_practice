// https://leetcode.cn/problems/maximize-total-cost-of-alternating-subarrays/solutions/2819339/zhuang-tai-ji-dpcong-ji-yi-hua-sou-suo-d-mtr9/
// class Solution {
// public:
//     long long maximumTotalCost(vector<int>& a) {
//         int n = a.size();
//         vector<array<long long, 2>> memo(n, {LLONG_MIN, LLONG_MIN});
//         auto dfs = [&](auto&& dfs, int i, int j) -> long long {
//             if (i == n) {
//                 return 0;
//             }
//             auto& res = memo[i][j]; // 注意这里是引用
//             if (res != LLONG_MIN) { // 之前计算过
//                 return res;
//             }
//             return res = max(dfs(dfs, i + 1, 1) + a[i],
//                              dfs(dfs, i + 1, j ^ 1) + (j == 0 ? a[i] : -a[i]));
//         };
//         return dfs(dfs, 0, 0);
//     }
// };

class Solution {
public:
    long long maximumTotalCost(vector<int>& a) {
        int n = a.size();
        vector<array<long long, 2>> f(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            f[i][0] = f[i + 1][1] + a[i];
            f[i][1] = max(f[i + 1][1] + a[i], f[i + 1][0] - a[i]);
        }
        return f[0][0];
    }
};

