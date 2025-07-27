// https://leetcode.cn/problems/maximum-number-of-subsequences-after-one-inserting/solutions/3734800/fu-yong-115-ti-dai-ma-qian-hou-zhui-fen-gtkqz/
class Solution {
public:
    long long numOfSubsequences(string s) {
        int t = ranges::count(s, 'T');
        long long l = 0, lc = 0, lct = 0, c = 0, ct = 0, lt = 0;
        for (char b : s) {
            if (b == 'L') {
                l++;
            } else if (b == 'C') {
                lc += l;
                c++;
            } else if (b == 'T') {
                lct += lc;
                ct += c;
                t--;
            }
            lt = max(lt, l * t);
        }
        return lct + max({ct, lc, lt});
    }
};
