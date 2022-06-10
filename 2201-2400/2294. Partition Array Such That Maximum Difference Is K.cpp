class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<int> cnt(100001, 0);
        int maxNum = -1;
        for(auto num: nums) {
            cnt[num]++;
            maxNum = max(num, maxNum);
        }
        int res = 0;
        for(int i = 0; i <= maxNum; ++i) {
            if(cnt[i]) {
                res++;
                i += k;
            }
        }
        
        return res;
    }
};
