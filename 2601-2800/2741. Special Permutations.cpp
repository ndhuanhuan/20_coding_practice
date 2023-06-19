// https://leetcode.cn/problems/special-permutations/solution/zhuang-ya-dp-by-endlesscheng-4jkr/
class Solution {
public:
    const int mod = 1e9 + 7;
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        // 二进制表示法:集合论与位运算
        int m = 1 << n;

        // 备忘录，进行剪枝
        vector<vector<int>> memo(m, vector<int>(n, -1));

        function<int(int, int)> dfs;
        dfs = [&](int i, int j)->int { // 可选的下标集合为 i，上次所选数的下标为 j。
            if(i == 0) {
                return 1;
            }
            int &res = memo[i][j];
            if(res != -1) {
                return res;
            } 
            int ans = 0;
            for(int k = 0; k < n; ++k) {
                int x = nums[k];
                if(((i >> k)&1) > 0 && (nums[j]%x == 0 || x%nums[j] == 0)) {
                    ans = (ans + dfs(i^(1<<k), k)) % mod;
                }
            }

            res = ans;
            return res;
        };

        int res = 0;
        for(int j = 0; j < n; ++j) {
            res = (res + dfs((m-1)^(1 << j), j)) % mod;
        }

        return res;
    }
};


// 递推
class Solution {
public:
    const int mod = 1e9 + 7;
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        // 二进制表示法:集合论与位运算
        int m = 1 << n;

        // dp 数组
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // base 
        for(int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int x = nums[j];
                for(int k = 0; k < n; ++k) {
                    int y = nums[k];
                    if(((i >> k) & 1) > 0 && (x % y == 0 || y % x == 0)) {
                        dp[i][j] = (dp[i][j] + dp[i^(1<<k)][k]) % mod;
                    }
                }
            }
        }

        int res = 0;
        for(int j = 0; j < n; ++j) {
            res = (res + dp[(m-1)^(1<<j)][j]) % mod;
        }
        return res;
    }
};
