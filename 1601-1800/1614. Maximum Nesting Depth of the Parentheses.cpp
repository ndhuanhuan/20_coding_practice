class Solution {
public:
    int maxDepth(string s) {
        int res = INT_MIN;
        int depth = 0;
        for(char c: s) {
            if(c == '(') {
                depth++;
            } else if(c == ')') {
                depth--;
            } else {
                res = max(res, depth);
            }
        }
        
        return res;
    }
};
