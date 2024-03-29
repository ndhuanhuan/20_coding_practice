// https://leetcode.com/problems/largest-number-after-mutating-substring/discuss/1360738/C%2B%2B-Greedy
class Solution {
public:
    string maximumNumber(string num, vector<int>& A) {
        bool changed = false;
        for (char &c : num) {
            int before = c - '0', after = A[before];
            if (after < before) {
                if (changed) break;
                continue;
            } else if (after == before) {
                continue;
            }
            changed = true;
            c = '0' + after;
        }
        return num;
    }
};
