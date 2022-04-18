// https://leetcode.com/problems/check-if-an-array-is-consecutive/discuss/1933286/c%2B%2B-or-O(n)-or-S(1)-or-find-missing-positive-or-neither-sort-nor-set
class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        const int n = nums.size();
        const auto min = *std::min_element(nums.begin(), nums.end());
        for(int i = 0 ; i < n; ++i) {
            while(nums[i] >= min+i  && nums[i] < min+n && nums[nums[i] - min] != nums[i]) {
                swap(nums[i], nums[nums[i]-min]);
            }
            
            if( nums[i] >= min+n || nums[i] < min+i) // out of range or repeated value
                return false;
        }
        
        return true;
    }
};
