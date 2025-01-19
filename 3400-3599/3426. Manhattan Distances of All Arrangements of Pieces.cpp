// https://leetcode.cn/problems/manhattan-distances-of-all-arrangements-of-pieces/solutions/3051398/gong-xian-fa-yu-chu-li-hou-o1pythonjavac-2hgt/
const int MOD = 1'000'000'007;
const int MX = 100'000;

long long F[MX]; // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i!^-1

long long pow(long long x, int n) {
    long long res = 1;
    for (; n; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = pow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

long long comb(int n, int m) {
    return F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

class Solution {
public:
    int distanceSum(int m, int n, int k) {
        return (m * n * (m * (1LL * n * n - 1) + n * (1LL * m * m - 1))) / 6 % MOD * comb(m * n - 2, k - 2) % MOD;
    }
};

