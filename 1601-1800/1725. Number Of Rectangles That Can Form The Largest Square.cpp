class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int cnt = 0;
        int gMax = 0;
        for(int i = 0; i < rectangles.size(); ++i) {
            vector<int> cur = rectangles[i];
            int curMax = min(cur[0], cur[1]);
            if(curMax > gMax) {
                gMax = curMax;
                cnt = 1;
            } else if(curMax == gMax) {
                cnt++;
            }
        }
        
        return cnt;
    }
};
