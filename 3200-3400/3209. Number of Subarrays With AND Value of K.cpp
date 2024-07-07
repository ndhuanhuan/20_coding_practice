// https://leetcode.cn/problems/number-of-subarrays-with-and-value-of-k/solutions/2833497/jian-ji-xie-fa-o1-kong-jian-pythonjavacg-u7fv/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (int j = i - 1; j >= 0 && (nums[j] & x) != nums[j]; j--) {
                nums[j] &= x;
            }
            ans += upper_bound(nums.begin(), nums.begin() + i + 1, k) -
                   lower_bound(nums.begin(), nums.begin() + i + 1, k);
        }
        return ans;
    }
};
