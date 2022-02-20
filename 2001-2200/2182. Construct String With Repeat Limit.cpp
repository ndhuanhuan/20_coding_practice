class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26, 0);
        for(auto c: s) {
            cnt[c-'a']++;
        }
        string res;
        while(true) {
            int i = 25;
            bool onlyOne = false;
            for(; i >= 0; --i) {
                if(res.size() && res.back()-'a' == i && cnt[i]) {
                    onlyOne = true;
                    continue;
                }
                if(cnt[i]) break; // this can be onlyOne or repeat limit one, it depends 
            }
            // cout << i << endl;
            if(i == -1) break;
            int fill = onlyOne ? 1 : min(cnt[i], repeatLimit);
            cnt[i] -= fill;
            while (fill--) res += 'a' + i;
        }
        
        return res;
    }
};
// https://leetcode.com/problems/construct-string-with-repeat-limit/discuss/1784775/Easy-understanding-C%2B%2B-code-with-comments
