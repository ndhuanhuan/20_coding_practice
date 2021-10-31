class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int res = -1;
        for(int i = 0; i < nums.size(); ++i) {
            int cur = i%10;
            if(cur == nums[i]) return i;
        }
        
        return res;
    }
};
