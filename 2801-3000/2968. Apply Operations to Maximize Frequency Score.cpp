// https://leetcode.cn/problems/apply-operations-to-maximize-frequency-score/solutions/2569301/hua-dong-chuang-kou-zhong-wei-shu-tan-xi-nuvr/
class Solution {
public:
    int maxFrequencyScore(vector<int> &nums, long long k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> s(n + 1, 0);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }

        // 把 nums[l] 到 nums[r] 都变成 nums[i]
        auto distance_sum = [&](int l, int i, int r) -> long long {
            long long left = (long long) nums[i] * (i - l) - (s[i] - s[l]);
            long long right = s[r + 1] - s[i + 1] - (long long) nums[i] * (r - i);
            return left + right;
        };

        int ans = 0, left = 0;
        for (int i = 0; i < n; i++) {
            while (distance_sum(left, (left + i) / 2, i) > k) {
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
