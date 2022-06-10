class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        
        for(auto& op: operations) {
            if(m2.count(op[0])) {
                int start = m2[op[0]];
                int end = op[1];
                m1[start] = end;
                m2[end] = start;
            } else {
                int start = op[0];
                int end = op[1];
                m1[start] = end;
                m2[end] = start;
            }
            
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if(m1.count(nums[i])) {
                nums[i] = m1[nums[i]];
            }
        }
        
        return nums;
    }
};
