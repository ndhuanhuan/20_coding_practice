// https://leetcode.cn/problems/painting-the-walls/solution/xuan-huo-bu-xuan-de-dian-xing-si-lu-by-e-ulcd/
class Solution {
public:
    int paintWalls(vector<int> &cost, vector<int> &time) {
        int n = cost.size(), f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int c = cost[i], t = time[i] + 1; // 注意这里加一了
            for (int j = n; j; j--)
                f[j] = min(f[j], f[max(j - t, 0)] + c);
        }
        return f[n];
    }
};

