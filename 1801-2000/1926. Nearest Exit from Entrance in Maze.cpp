// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/discuss/1329116/BFS
class Solution {
public:
    int dir[5] = {0, -1, 0, 1, 0};
    int nearestExit(vector<vector<char>>& m, vector<int>& ent) {
        queue<vector<int>> q; // i, j, step
        q.push({ent[0], ent[1], 0});
        while(!q.empty()) {
            vector<int> element = q.front();
            q.pop();
            int i = element[0], j = element[1], steps = element[2];
            if ((i != ent[0] || j != ent[1]) && (i == 0 || j == 0 || i == m.size() - 1 || j == m[i].size() - 1))
                return steps;
            for (int d = 0; d < 4; ++d) {
                int di = i + dir[d], dj = j + dir[d + 1];
                if (di >= 0 && dj >= 0 && di < m.size() && dj < m[di].size() && m[di][dj] == '.') {
                    m[di][dj] = '+';
                    q.push({di, dj, steps + 1});
                }
            }
        }
        return -1;
    }
};
