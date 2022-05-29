class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> m(256, 0);
        vector<int> m2(256, 0);
        for(auto c: s) {
            m[c]++;
        }
        
        for(auto c: target) {
            m2[c]++;
        }
        
        int res = INT_MAX;
        
        
        for(auto c: target) {
            res = min(res, m[c] / m2[c]);
        }
        
        return res;
    }
};
