class Solution {
public:
    int countSubMultisets(vector<int> &nums, int l, int r) {
        const int MOD = 1e9 + 7;
        int total = 0;
        unordered_map<int, int> cnt;
        for (int x: nums) {
            total += x;
            cnt[x]++;
        }
        if (l > total) {
            return 0;
        }

        r = min(r, total);
        vector<int> f(r + 1);
        f[0] = cnt[0] + 1;
        cnt.erase(0);

        int sum = 0;
        for (auto [x, c]: cnt) {
            auto new_f = f;
            sum = min(sum + x * c, r); // 到目前为止，能选的元素和至多为 sum
            for (int j = x; j <= sum; j++) { // 把循环上界从 r 改成 sum 可以快不少
                new_f[j] = (new_f[j] + new_f[j - x]) % MOD;
                if (j >= (c + 1) * x) {
                    new_f[j] = (new_f[j] - f[j - (c + 1) * x] + MOD) % MOD; // 避免减法产生负数
                }
            }
            f = move(new_f);
        }

        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans = (ans + f[i]) % MOD;
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/count-of-sub-multisets-with-bounded-sum/solutions/2482876/duo-zhong-bei-bao-fang-an-shu-cong-po-su-f5ay/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
