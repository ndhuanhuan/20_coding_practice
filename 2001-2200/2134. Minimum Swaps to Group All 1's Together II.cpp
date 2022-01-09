// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/discuss/1676874/Sliding-Window
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = count(begin(nums), end(nums), 1), n = nums.size(), res = n;
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
            while (j - i < ones)
                cnt += nums[j++%n];
            res = min(res, ones - cnt);
            cnt -= nums[i];
        }
        return res;
    }
};
