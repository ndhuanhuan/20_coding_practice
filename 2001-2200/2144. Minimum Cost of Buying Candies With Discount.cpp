class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        const int n = cost.size();
        int res = 0, i = cost.size() - 1;
        while(i >= 0) {
            if( (n-i) % 3 == 0) {
                --i;
                continue;
            }
            
            res += cost[i];
            --i;
        }
        
        return res;
    }
};
