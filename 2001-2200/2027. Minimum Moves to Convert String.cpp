class Solution {
public:
    int minimumMoves(string s) {
        int res = 0, i = 0, n = s.size();
        while(i < n) {
            if(s[i] == 'X') {
                res += 1;
                i += 3;
            } else {
                ++i;
            }
        }
        return res;
    }
};
