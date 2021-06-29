// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/discuss/1298766/C%2B%2B-Simple-solution-Faster-than-100
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x = s;
        int n = s.size(), m = part.size(), i, j;
        for (i = 0, j = 0; i < n; i++) {
            x[j++] = s[i];
            if (j >= m && x.substr(j - m, m) == part)
                j -= m;
        }
        return x.substr(0, j);
    }
};
