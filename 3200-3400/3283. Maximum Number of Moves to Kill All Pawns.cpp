// https://leetcode.cn/problems/maximum-number-of-moves-to-kill-all-pawns/solutions/2909069/pai-lie-xing-zhuang-ya-dpxiang-lin-xiang-q49q/
class Solution {
    static constexpr int dirs[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        int dis[n][50][50];
        memset(dis, -1, sizeof(dis));
        // 计算马到兵的步数，等价于计算兵到其余格子的步数
        for (int i = 0; i < n; i++) {
            int px = positions[i][0], py = positions[i][1];
            dis[i][px][py] = 0;
            vector<pair<int, int>> q = {{px, py}};
            for (int step = 1; !q.empty(); step++) {
                vector<pair<int, int>> tmp;
                for (auto& [qx, qy] : q) {
                    for (auto& dir : dirs) {
                        int x = qx + dir[0], y = qy + dir[1];
                        if (0 <= x && x < 50 && 0 <= y && y < 50 && dis[i][x][y] < 0) {
                            dis[i][x][y] = step;
                            tmp.emplace_back(x, y);
                        }
                    }
                }
                q = move(tmp);
            }
        }

        positions.push_back({kx, ky});
        vector<vector<int>> memo(n + 1, vector<int>(1 << n, -1)); // -1 表示没有计算过
        int u = (1 << n) - 1;
        auto dfs = [&](auto&& dfs, int i, int mask) -> int {
            if (mask == 0) {
                return 0;
            }
            int& res = memo[i][mask]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            int x = positions[i][0], y = positions[i][1];
            if (__builtin_parity(u ^ mask) == 0) { // Alice 操作
                for (int j = 0; j < n; j++) {
                    if (mask >> j & 1) {
                        res = max(res, dfs(dfs, j, mask ^ (1 << j)) + dis[j][x][y]);
                    }
                }
            } else { // Bob 操作
                res = INT_MAX;
                for (int j = 0; j < n; j++) {
                    if (mask >> j & 1) {
                        res = min(res, dfs(dfs, j, mask ^ (1 << j)) + dis[j][x][y]);
                    }
                }
            }
            return res;
        };
        return dfs(dfs, n, u);
    }
};
