class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m = spaces.size();
        int n = s.size();
        
        if(m == 0) return s;
        int j = 0;
        
        string res = "";
        for(int i = 0; i < n; ++i) {
            if(j < m && i == spaces[j]) {
                res += " ";
                ++j;
            }
            
            res += s[i];
        }
        
        return res;
    }
};
