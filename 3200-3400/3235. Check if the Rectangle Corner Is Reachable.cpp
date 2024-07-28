// https://leetcode.cn/problems/check-if-the-rectangle-corner-is-reachable/solutions/2860214/deng-jie-zhuan-huan-bing-cha-ji-pythonja-yf9y/
class Solution {
public:
    bool canReachCorner(int x, int y, vector<vector<int>>& a) {
        int n = a.size();
        // 并查集中的 n 表示左边界或上边界，n+1 表示下边界或右边界
        vector<int> fa(n + 2);
        iota(fa.begin(), fa.end(), 0);
        // 非递归并查集
        auto find = [&](int x) {
            int rt = x;
            while (fa[rt] != rt) {
                rt = fa[rt];
            }
            while (fa[x] != rt) {
                int temp = fa[x];
                fa[x] = rt;
                x = temp;
            }
            return rt;
        };
        auto merge = [&](int x, int y) {
            fa[find(x)] = find(y);
        };

        for (int i = 0; i < a.size(); i++) {
            int ox = a[i][0], oy = a[i][1], r = a[i][2];
            if (ox <= r || oy + r >= y) { // 圆 i 和左边界或上边界有交集
                merge(i, n);
            }
            if (oy <= r || ox + r >= x) { // 圆 i 和下边界或右边界有交集
                merge(i, n + 1);
            }
            for (int j = 0; j < i; j++) {
                int qx = a[j][0], qy = a[j][1], qr = a[j][2];
                if ((long long) (ox - qx) * (ox - qx) + (long long) (oy - qy) * (oy - qy) <= (long long) (r + qr) * (r + qr)) {
                    merge(i, j); // 圆 i 和圆 j 有交集
                }
            }
            if (find(n) == find(n + 1)) { // 无法到达终点
                return false;
            }
        }
        return true;
    }
};

