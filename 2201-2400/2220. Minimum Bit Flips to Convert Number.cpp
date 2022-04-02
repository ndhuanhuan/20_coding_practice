// Time: O(1)
// Space: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};

class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s = helper(start);
        string g = helper(goal);
        
        if (s.size() < g.size()) {
            while(s.size() < g.size()) s = "0" + s;
        } else {
            while(g.size() < s.size()) g = "0" + g;
        }
        
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != g[i]) res++;
        }
        
        return res;
    }
    
    string helper(int num) {
        string res = "";
        while(num) {
            if(num%2) {
                res = "1" + res;
            } else {
                res = "0" + res;
            }
            num /= 2;
        }
        // cout << res << endl;
        return res;
    }
};
