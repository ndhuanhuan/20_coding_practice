// https://leetcode.cn/problems/power-of-heroes/solution/gong-xian-fa-pythonjavacgo-by-endlessche-d4jx/
// https://www.bilibili.com/video/BV1fV4y1r7e6/?vd_source=48e4bed01dd155111c1b309b768743f6
class Solution {
public:
    int sumOfPower(vector<int> &nums) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int ans = 0, s = 0;
        for (long long x: nums) {
            ans = (ans + x * x % MOD * (x + s)) % MOD; // 中间模一次防止溢出
            s = (s * 2 + x) % MOD;
        }
        return ans;
    }
};

