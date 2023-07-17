// https://www.bilibili.com/video/BV1DM4y1x7bR/?vd_source=48e4bed01dd155111c1b309b768743f6
// https://leetcode.cn/problems/length-of-the-longest-valid-substring/solution/ha-xi-biao-shuang-zhi-zhen-pythonjavacgo-bcez/
class Solution {
public:
    int longestValidSubstring(string word, vector<string> &forbidden) {
        unordered_set<string> fb{forbidden.begin(), forbidden.end()};
        int ans = 0, left = 0, n = word.length();
        for (int right = 0; right < n; right++) {
            for (int i = right; i >= left && i > right - 10; i--) {
                if (fb.count(word.substr(i, right - i + 1))) {
                    left = i + 1; // 当子串右端点 >= right 时，合法子串一定不能包含 word[i]
                    break;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
