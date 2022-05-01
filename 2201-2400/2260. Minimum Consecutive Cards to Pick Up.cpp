class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> m;
        const int n = cards.size();
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if(m.count(cards[i])) {
                res = min(res, i - m[cards[i]] + 1);
            } 
            
            m[cards[i]] = i;
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
