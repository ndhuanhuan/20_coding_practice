class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        // top to down
        vector<vector<int>> twoV(m + 1, vector<int>(n + 1, 0));
        
        // left to right
        vector<vector<int>> twoH(m + 1, vector<int>(n + 1, 0));
        
         // top to down
        vector<vector<int>> fiveV(m + 1, vector<int>(n + 1, 0));
        
        // left to right
        vector<vector<int>> fiveH(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int cur = grid[i][j];
                int cntTwo = helper(cur, 2);
                int cntFive = helper(cur, 5);
                
                twoV[i][j] = i > 0 ? (twoV[i-1][j] + cntTwo) : cntTwo;
                twoH[i][j] = j > 0 ? (twoH[i][j-1] + cntTwo) : cntTwo;
                
                fiveV[i][j] = i > 0 ? (fiveV[i-1][j] + cntFive) : cntFive;
                fiveH[i][j] = j > 0 ? (fiveH[i][j-1] + cntFive) : cntFive;
                
                
            }
        }
        
        
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {

                int curTwo = j > 0 ? (twoH[i][j] - twoH[i][j-1]) : twoH[i][j];
                int leftTwo = j > 0 ? twoH[i][j - 1] : 0;
                int rightTwo = twoH[i][n-1] - twoH[i][j];
                int upTwo = i > 0 ? twoV[i-1][j] : 0;
                int downTwo = twoV[m-1][j] - twoV[i][j];
                
                int curFive = j > 0 ? (fiveH[i][j] - fiveH[i][j-1]) : fiveH[i][j];
                int leftFive = j > 0 ? fiveH[i][j - 1] : 0;
                int rightFive = fiveH[i][n-1] - fiveH[i][j];
                int upFive = i > 0 ? fiveV[i-1][j] : 0;
                int downFive = fiveV[m-1][j] - fiveV[i][j];

                
                res = max(res, min(leftTwo + curTwo + upTwo, leftFive + curFive + upFive));
                
                res = max(res, min(rightTwo + curTwo + upTwo, rightFive + curFive + upFive));
                
                res = max(res, min(leftTwo + curTwo + downTwo, leftFive + curFive + downFive));
                
                res = max(res, min(rightTwo + curTwo + downTwo, rightFive + curFive + downFive));

                
            }
        }
        
        return res;
        
    }
    
    int helper(int cur, int div) {
        int cnt = 0;
        while(cur%div == 0) {
            cnt++;
            cur /= div;
        }
        
        return cnt;
    }
};
