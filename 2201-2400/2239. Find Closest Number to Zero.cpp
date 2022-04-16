class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int candidate = INT_MAX;
        const int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            if(abs(nums[i]) < abs(candidate)) {
                candidate = nums[i];
            } else if (abs(nums[i]) == abs(candidate)) {
                candidate = (nums[i] > candidate) ? nums[i]: candidate;
            }
        }
        
        return candidate;
    }
};
