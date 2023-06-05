// https://leetcode.cn/problems/count-of-integers/solution/shu-wei-dp-tong-yong-mo-ban-pythonjavacg-9tuc/
class Solution {
    const int MOD = 1e9 + 7;

    int f(string s, int min_sum, int max_sum) {
        int n = s.length(), memo[n][min(9 * n, max_sum) + 1];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
        function<int(int, int, bool)> f = [&](int i, int sum, bool is_limit) -> int {
            if (sum > max_sum) return 0; // 非法数字
            if (i == n) return sum >= min_sum;
            if (!is_limit && memo[i][sum] != -1) return memo[i][sum];
            int res = 0;
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; ++d) // 枚举要填入的数字 d
                res = (res + f(i + 1, sum + d, is_limit && d == up)) % MOD;
            if (!is_limit) memo[i][sum] = res;
            return res;
        };
        return f(0, 0, true);
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int ans = f(num2, min_sum, max_sum) - f(num1, min_sum, max_sum) + MOD; // 避免负数
        int sum = 0;
        for (char c: num1) sum += c - '0';
        ans += min_sum <= sum && sum <= max_sum; // x=num1 是合法的，补回来
        return ans % MOD;
    }
};
