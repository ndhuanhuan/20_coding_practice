// https://leetcode.com/problems/truncate-sentence/discuss/1141462/C%2B%2B-Pointer
class Solution {
public:
    string truncateSentence(string s, int k) {
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == ' ' && --k == 0)
                return s.substr(0, i);
        return s;
    }
};
