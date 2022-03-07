// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/discuss/1821936/List-vs.-BIT
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0;
        list<char> l(begin(s), end(s));
        while(l.size() > 1) {
            auto it = begin(l);
            int step = 0;
            for (; *it != l.back(); ++it)
                ++step;
            res += step == l.size() - 1 ? step / 2 : step;
            if (it != prev(end(l)))
                l.erase(it);
            l.pop_back();
        }
        return res;
    }
};
