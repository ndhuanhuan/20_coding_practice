// https://leetcode.cn/problems/minimum-array-length-after-pair-removals/solutions/2446146/olog-n-tan-xin-er-fen-cha-zhao-pythonjav-t3qn/
class Solution {
public:
    int minLengthAfterRemovals(vector<int> &nums) {
        int n = nums.size();
        int x = nums[n / 2];
        int max_cnt = upper_bound(nums.begin(), nums.end(), x) -
                      lower_bound(nums.begin(), nums.end(), x);
        return max(max_cnt * 2 - n, n % 2);
    }
};
