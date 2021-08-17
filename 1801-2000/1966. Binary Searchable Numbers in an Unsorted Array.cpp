// https://leetcode.com/problems/binary-searchable-numbers-in-an-unsorted-array/discuss/1401975/Two-Swipes
class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int res = 0, max_l = INT_MIN, min_r = INT_MAX, found_l[100001] = {};
        for (int i = 0; i < nums.size(); max_l = max(max_l, nums[i++]))
            found_l[i] = max_l < nums[i];
        for (int i = nums.size() - 1; i >= 0; min_r = min(min_r, nums[i--]))
            res += found_l[i] && nums[i] < min_r;
        return res;
    }
};
