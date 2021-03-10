// https://zxi.mytechroad.com/blog/geometry/leetcode-1779-find-nearest-point-that-has-the-same-x-or-y-coordinate/
class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int min_dist = INT_MAX;
    int ans = -1;
    for (int i = 0; i < points.size(); ++i) {
      const int dx = abs(points[i][0] - x);
      const int dy = abs(points[i][1] - y);      
      if (dx * dy == 0 && dx + dy < min_dist) {
        min_dist = dx + dy;
        ans = i;
      }
    }
    return ans;
  }
};
