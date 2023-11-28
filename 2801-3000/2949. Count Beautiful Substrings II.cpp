// https://leetcode.com/problems/count-beautiful-substrings-ii/discuss/4330696/JavaC%2B%2BPython-HashMap
// https://leetcode.cn/problems/count-beautiful-substrings-ii/solutions/2542274/fen-jie-zhi-yin-zi-qian-zhui-he-ha-xi-bi-ceil/
class Solution {

public:
    long long beautifulSubstrings(string s, int k) {
        int n = s.length(), v = 0, l;
        for (l = 1; l * l % (k * 4); ++l);
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<unordered_map<int, int>> seen(l);
        seen[l - 1][0] = 1;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            v += vowels.find(s[i]) != vowels.end() ? 1: -1;
            res += seen[i % l][v]++;
        }
        return res;
    }
};
