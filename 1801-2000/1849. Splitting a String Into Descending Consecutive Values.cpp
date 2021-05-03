// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/discuss/1186795/C%2B%2B-Backtracking-solution.-O(N-2)-and-time-complexity-analytics
long long MX = 999999999999;
class Solution {
public:
    bool dfs(string &s, long long prev, int idx, int cnt) {
        if(idx == s.size() ) return cnt > 1;
        long long num = 0;
        for(int i = idx; i < s.size(); i++) {
            num = num *  10l + s[i] - '0';
            if(num > MX) break;
            if(num == prev - 1 || prev == -1) {
                if(dfs(s, num, i + 1, cnt + 1)) return true;
            }
            if(num > prev && prev != -1) break;
        }
        return false;
    }
    
    bool splitString(string s) {
        if(s.size() <= 1) return false;
        return dfs(s, -1, 0, 0);
    }
};
