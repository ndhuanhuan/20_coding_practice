// https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range/solutions/2396206/shu-wei-dppythonjavacgo-by-endlesscheng-4gvw/
class Solution {
    int calc(int high, int k) {
        auto s = to_string(high);
        int n = s.length(), memo[n][k + 1][n * 2 + 1];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
        function<int(int, int, int, bool, bool)> dfs;
        dfs = [&](int i, int val, int diff, bool is_limit, bool is_num) -> int {
            if (i == n)
                return is_num && val == 0 && diff == n; // 找到了一个合法数字
            if (!is_limit && is_num && memo[i][val][diff] != -1)
                return memo[i][val][diff];
            int res = 0;
            if (!is_num) // 可以跳过当前数位
                res = dfs(i + 1, val, diff, false, false);
            int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 high 的一样，那么这一位至多填数字 s[i]（否则就超过 high 啦）
            for (int d = 1 - is_num; d <= up; d++) // 枚举要填入的数字 d
                res += dfs(i + 1, (val * 10 + d) % k, diff + d % 2 * 2 - 1, is_limit && d == up, true);
            if (!is_limit && is_num)
                memo[i][val][diff] = res; // 记忆化
            return res;
        };
        return dfs(0, 0, n, true, false);
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return calc(high, k) - calc(low - 1, k);
    }

};
