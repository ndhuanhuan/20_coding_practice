// 预处理每个数的真因子，时间复杂度 O(MX*logMX)
const int MX = 201;
vector<vector<int>> divisors(MX);
int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
    int get_modify(string s) {
        int n = s.length();
        int res = n;
        for (int d: divisors[n]) {
            int cnt = 0;
            for (int i0 = 0; i0 < d; i0++) {
                for (int i = i0, j = n - d + i0; i < j; i += d, j -= d) {
                    cnt += s[i] != s[j];
                }
            }
            res = min(res, cnt);
        }
        return res;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> modify(n - 1, vector<int>(n));
        for (int left = 0; left < n - 1; left++) {
            for (int right = left + 1; right < n; right++) {
                modify[left][right] = get_modify(s.substr(left, right - left + 1));
            }
        }

        vector<vector<int>> memo(k, vector<int>(n, n + 1)); // n+1 表示没有计算过
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == 0) {
                return modify[0][j];
            }
            int &res = memo[i][j]; // 注意这里是引用
            if (res <= n) { // 之前计算过
                return res;
            }
            for (int L = i * 2; L < j; L++) {
                res = min(res, dfs(i - 1, L - 1) + modify[L][j]);
            }
            return res;
        };
        return dfs(k - 1, n - 1);
    }
};

