class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int mx_cnt = 0;
        int mx = -1;
        const int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n - 1; ++i) {
            if(nums[i] == key) {
                m[nums[i+1]]++;
                if(m[nums[i+1]] > mx_cnt) {
                    mx_cnt = m[nums[i+1]];
                    mx = nums[i+1];
                }
            }
        }
        
        return mx;
    }
};
