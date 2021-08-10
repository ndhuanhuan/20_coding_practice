// https://leetcode.com/problems/check-if-move-is-legal/discuss/1390122/Trace-in-8-directions
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int dir[10] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
        for (int d = 0; d < 9; ++d) {
            if(d == 4) // duplicate, skip
                continue;
            for (int x = 1; ; ++x) {
                int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
                if (i < 0 || j < 0 || i >= 8 || j >= 8 || board[i][j] == '.')
                    break;
                if (board[i][j] == color) {
                    if (x > 1)
                        return true;
                    break;
                }
            }
        }
            
        return false;
    }
};
