// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/discuss/1330165/Left-and-right-and-inbetween
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i)
            if (first[i] < last[i])
                res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
        return res;
    }
};
