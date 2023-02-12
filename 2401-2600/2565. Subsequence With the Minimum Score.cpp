// https://leetcode.cn/problems/subsequence-with-the-minimum-score/solution/qian-hou-zhui-fen-jie-san-zhi-zhen-pytho-6cmr/
class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.length(), m = t.length(), suf[n + 1];
        suf[n] = m;
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            if (j >= 0 && s[i] == t[j]) --j;
            suf[i] = j + 1;
        }
        int ans = suf[0]; // 删除 t[:suf[0]]
        if (ans == 0) return 0;
        for (int i = 0, j = 0; i < n; ++i)
            if (s[i] == t[j]) // 注意 j 不会等于 m，因为上面 suf[0]>0 表示 t 不是 s 的子序列
                ans = min(ans, suf[i + 1] - ++j); // ++j 后，删除 t[j:suf[i+1]]
        return ans;
    }
};

