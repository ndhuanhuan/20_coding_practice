// https://zxi.mytechroad.com/blog/geometry/leetcode-1637-widest-vertical-area-between-two-points-containing-no-points/
class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(begin(points), end(points), [](const auto& p1, const auto& p2) {
      return p1[0] != p2[0] ? p1[0] < p2[0] : p1[1] < p2[1];
    });
    int ans = 0;
    for (int i = 1; i < points.size(); ++i)
      ans = max(ans, points[i][0] - points[i - 1][0]);
    return ans;
  }
};
