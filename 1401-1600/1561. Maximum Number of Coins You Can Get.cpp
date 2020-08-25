
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        const int n = piles.size();
        int res = 0;
        sort(piles.begin(), piles.end());
        for(int i = n - 2, picked  = 0; picked < n / 3; i-=2, picked++) {
            res += piles[i];
        }
        
        return res;
    }
};
