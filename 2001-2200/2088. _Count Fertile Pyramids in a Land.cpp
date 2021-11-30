// https://leetcode.com/problems/count-fertile-pyramids-in-a-land/discuss/1598908/Simple-DP-Solution-with-Explanation-or-C%2B%2B-or-O(n-*-m)
class Solution {
public:
    int count(vector<vector<int>> grid){
        int i, j, n = grid.size(), m = grid[0].size(), ans = 0;
        for(i = 1; i < n; i++){
            for(j = 1; j < m - 1; j++){
                if(grid[i][j] && grid[i - 1][j]){ // check if current cell can be a tip of pyramid or not.
                    grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j + 1]) + 1; // if its a pyramid, find the height.
                    ans += grid[i][j] - 1;
					// pyramid of size n contributes n - 1 times to the answer.
                }
            }
        }
        return ans;
    }
    int countPyramids(vector<vector<int>>& grid) {
        int ans = count(grid); // this will count inverse pyramid.
        reverse(grid.begin(), grid.end());  
        ans += count(grid); // this will count simple pyramid.
        return ans;
    }
};
