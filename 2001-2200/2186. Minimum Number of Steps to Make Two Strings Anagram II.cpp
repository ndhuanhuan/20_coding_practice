class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        for(auto c: s) {
            v[c - 'a']++;
        }
        
        for(auto c: t) {
            v[c- 'a']--;
        }
        
        int res = 0;
        for(int i = 0; i < 26; ++i) {
            if(v[i] != 0) {
                res += abs(v[i]);
            }
        }
        
        return res;
    }
};
