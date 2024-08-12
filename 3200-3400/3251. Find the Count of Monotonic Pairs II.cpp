// https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii/solutions/2876190/qian-zhui-he-you-hua-dppythonjavacgo-by-3biek/
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        int m = ranges::max(nums);
        vector<vector<long long>> f(n, vector<long long>(m + 1));
        vector<long long> s(m + 1);

        fill(f[0].begin(), f[0].begin() + nums[0] + 1, 1);
        for (int i = 1; i < n; i++) {
            partial_sum(f[i - 1].begin(), f[i - 1].end(), s.begin()); // f[i-1] 的前缀和
            for (int j = 0; j <= nums[i]; j++) {
                int max_k = j + min(nums[i - 1] - nums[i], 0);
                f[i][j] = max_k >= 0 ? s[max_k] % MOD : 0;
            }
        }

        return reduce(f[n - 1].begin(), f[n - 1].begin() + nums[n - 1] + 1, 0LL) % MOD;
    }
};

