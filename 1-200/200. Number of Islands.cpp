// https://leetcode.com/problems/number-of-islands/discuss/584741/C%2B%2B-UnionFindBFSDFS
class UnionFind {
    vector<int> id;
public:
    UnionFind(int N) : id(N) {
        iota(begin(id), end(id), 0);
    }
    void connect(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b) return;
        id[a] = b;
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
};
class Solution {
    int M, N;
    int key(int x, int y) { return x * N + y; }
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int numIslands(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        M = A.size(), N = A[0].size();
        UnionFind uf(M * N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') continue;
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || y < 0 || x >= M || y >= N || A[x][y] == '0') continue;
                    uf.connect(key(i, j), key(x, y));
                }
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') continue;
                s.insert(uf.find(key(i, j)));
            }
        }
        return s.size();
    }
};



//sample 9 ms submission
//http://www.cnblogs.com/grandyang/p/4402656.html
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        if (grid.empty() || grid[0].empty())
            return 0;
        
        
        //find first land
        
        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfsSweep(grid, i, j);
                    islandCount++;
                }
            } //end for j
        }// end for i
       
      return islandCount;  
    }
void dfsSweep(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1')
        return;

    if (grid[r][c] == '0')
        return;
    
    grid[r][c] = '0';

    //top
    dfsSweep(grid, r-1,c);
    //left
    dfsSweep(grid, r, c-1);
    //right
    dfsSweep(grid, r, c+1);
    //bottom
    dfsSweep(grid, r+1,c);
}
};
