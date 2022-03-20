class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> cnt(510, 0);
        int invalidPairs = 0;
        const int n = nums.size();
        if(n % 2) return false;
        
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            cnt[num]++;
            if(cnt[num]%2) invalidPairs++;
            else invalidPairs--;
        }
        
        return invalidPairs == 0;
    }
};
