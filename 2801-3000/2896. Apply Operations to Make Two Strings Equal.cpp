// https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal/solutions/2472122/ji-yi-hua-sou-suo-by-endlesscheng-64vq/
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        if (s1 == s2) return 0;
        vector<int> p;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                p.push_back(i);
        if (p.size() % 2) return -1;
        int f0 = 0, f1 = x;
        for (int i = 1; i < p.size(); i++) {
            int new_f = min(f1 + x, f0 + (p[i] - p[i - 1]) * 2);
            f0 = f1;
            f1 = new_f;
        }
        return f1 / 2;
    }
};
