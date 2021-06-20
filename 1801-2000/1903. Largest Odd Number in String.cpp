// https://leetcode.com/problems/largest-odd-number-in-string/discuss/1284313/Search-for-rightmost-odd-digit
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i)
            if ((num[i] - '0') % 2)
                return num.substr(0, i + 1);
        return string();
    }
};
