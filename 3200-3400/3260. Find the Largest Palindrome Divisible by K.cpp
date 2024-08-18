// https://leetcode.cn/problems/find-the-largest-palindrome-divisible-by-k/solutions/2884548/tong-yong-zuo-fa-jian-tu-dfsshu-chu-ju-t-m3pu/
class Solution {
public:
    string largestPalindrome(int n, int k) {
        vector<int> pow10(n);
        pow10[0] = 1;
        for (int i = 1; i < n; i++) {
            pow10[i] = pow10[i - 1] * 10 % k;
        }

        string ans(n, 0);
        int m = (n + 1) / 2;
        vector<vector<int>> vis(m + 1, vector<int>(k));
        auto dfs = [&](auto&& dfs, int i, int j) -> bool {
            if (i == m) {
                return j == 0;
            }
            vis[i][j] = true;
            for (int d = 9; d >= 0; d--) { // 贪心：从大到小枚举
                int j2;
                if (n % 2 && i == m - 1) { // 正中间
                    j2 = (j + d * pow10[i]) % k;
                } else {
                    j2 = (j + d * (pow10[i] + pow10[n - 1 - i])) % k;
                }
                if (!vis[i + 1][j2] && dfs(dfs, i + 1, j2)) {
                    ans[i] = ans[n - 1 - i] = '0' + d;
                    return true;
                }
            }
            return false;
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};

