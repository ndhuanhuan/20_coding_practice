class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(100, 0);
        
        for(int c: candidates) {
            int bit = 0;
            while(c > 0) {
                if(c & 1) {
                    cnt[bit]++;
                }
                c = c >> 1;
                bit++;
            }
        }
        
        int res = 0;
        
        for(int i = 0; i < cnt.size(); ++i) {
            res = max(res, cnt[i]);
        }
        
        return res;
    }
};
