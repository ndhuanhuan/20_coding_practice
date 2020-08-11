//http://www.cnblogs.com/grandyang/p/4329128.html
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != nums[j]) nums[++j] = nums[i];
        }
        return j + 1;
    }
};
