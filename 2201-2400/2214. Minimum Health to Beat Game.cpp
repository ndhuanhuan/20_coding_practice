class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long total = 0;
        int curMax = 0;
        
        for(int i = 0; i < damage.size(); ++i) {
            total += damage[i];
            curMax = max(curMax, damage[i]);
        }
        
        curMax = min(armor, curMax);
        
        return total - curMax + 1 >= 0 ? total - curMax + 1 : 0;
    }
};
