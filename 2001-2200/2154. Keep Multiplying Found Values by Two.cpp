class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, bool> m;
        for(auto num: nums) {
            m[num] = true;
        }
        int res = original;
        while(m.count(res)) {
            res *= 2;
        }
        
        return res;
    }
};
