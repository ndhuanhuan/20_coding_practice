// https://www.bilibili.com/video/BV1Em4y1T7Bq/?vd_source=48e4bed01dd155111c1b309b768743f6
class Solution {
public:
    long long getMaxFunctionValue(vector<int> &receiver, long long K) {
        int n = receiver.size();
        int m = 64 - __builtin_clzll(K); // K 的二进制长度
        vector<vector<pair<int, long long>>> pa(m, vector<pair<int, long long>>(n));
        for (int i = 0; i < n; i++)
            pa[0][i] = {receiver[i], receiver[i]};
        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                auto [p, s] = pa[i][x];
                auto [pp, ss] = pa[i][p];
                pa[i + 1][x] = {pp, s + ss}; // 合并节点值之和
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = i;
            int x = i;
            for (long long k = K; k; k &= k - 1) {
                auto [p, s] = pa[__builtin_ctzll(k)][x];
                sum += s;
                x = p;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

