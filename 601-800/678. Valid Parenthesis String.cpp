class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        
        for(char c: s) {
            if(c == '(') {
                cmin++;
                cmax++;
            } else if(c == ')') {
                cmin--;
                cmax--;
            } else {
                cmax++;
                cmin--;
            }
            
            if(cmax < 0) return false;
            cmin = max(cmin, 0); // right parenthese cannot go below 0, we can assume all matching if it is below 0
        }
        
        return cmin == 0;
    }
};


// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-678-valid-parenthesis-string/
class Solution {
public:
    bool checkValidString(string s) {
        int min_op = 0;
        int max_op = 0;
        
        for (char c : s) {
            if (c == '(') ++min_op; else --min_op;
            if (c != ')') ++max_op; else --max_op;
            if (max_op < 0) return false;
            min_op = max(0, min_op);
        }
        
        return min_op == 0;
    }
};
