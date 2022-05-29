class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        auto isValid = [&](int i, int j)->bool {
            return 0 <= i && i < m
                && 0 <= j && j < n;
        };
        
        int di[] = {0,0,1,-1};
        int dj[] = {1,-1,0,0};
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<array<int, 3>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({-dist[0][0], 0, 0});
        while (pq.size()) {
            auto [d, i, j] = pq.top();
            pq.pop();
            d = -d;
            if (i == m-1 && j == n-1)
                break;
            if (d > dist[i][j])
                continue;
            for (int z: {0,1,2,3}) {
                int ni = i + di[z];
                int nj = j + dj[z];
                if (isValid(ni, nj)) {
                    int nd = d + grid[ni][nj];
                    if (dist[ni][nj] > nd) {
                        dist[ni][nj] = nd;
                        pq.push({-nd, ni, nj});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};
