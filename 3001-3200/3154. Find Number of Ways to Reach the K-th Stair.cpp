// https://leetcode.cn/problems/find-number-of-ways-to-reach-the-k-th-stair/solutions/2782792/liang-chong-fang-fa-ji-yi-hua-sou-suo-zu-j227/
class Solution {
    unordered_map<long long, int> memo;

    int dfs(int i, int j, bool preDown, int k) {
        if (i > k + 1) {
            return 0;
        }
        long long p = (long long) i << 32 | j << 1 | preDown; // 用一个 long long 表示状态
        if (memo.contains(p)) { // 之前算过了
            return memo[p];
        }
        int res = i == k;
        res += dfs(i + (1 << j), j + 1, false, k); // 操作二
        if (i && !preDown) {
            res += dfs(i - 1, j, true, k); // 操作一
        }
        return memo[p] = res; // 记忆化
    };

public:
    int waysToReachStair(int k) {
        return dfs(1, 0, false, k);
    }
};
