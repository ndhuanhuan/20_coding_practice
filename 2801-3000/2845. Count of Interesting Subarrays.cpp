// https://leetcode.cn/problems/count-of-interesting-subarrays/solutions/2424063/qian-zhui-he-ha-xi-biao-fu-ti-dan-by-end-74bb/
class Solution {
public:
    long long countInterestingSubarrays(vector<int> &nums, int mod, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1; // 把 s[0]=0 算进去
        long long ans = 0;
        int s = 0;
        for (int x: nums) {
            s += x % mod == k;
            ans += cnt[(s - k + mod) % mod]; // +mod 避免减法出现负数
            cnt[s % mod]++;
        }
        return ans;
    }
};
