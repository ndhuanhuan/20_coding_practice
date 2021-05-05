// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1847-closest-room/
class Solution {
public:
  vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
    const int n = rooms.size();
    const int m = queries.size();
    for (int i = 0; i < m; ++i)
      queries[i].push_back(i);
    // Sort queries by size DESC.
    sort(begin(queries), end(queries), [](const auto& q1, const auto& q2){
      return q1[1] > q2[1];
    });
    // Sort room by size DESC.
    sort(begin(rooms), end(rooms), [](const auto& r1, const auto& r2) {
      return r1[1] > r2[1];
    });
    vector<int> ans(m); 
    int j = 0;
    set<int> ids;
    for (const auto& q : queries) {
      while (j < n && rooms[j][1] >= q[1])
        ids.insert(rooms[j++][0]);      
      if (ids.empty()) {
        ans[q[2]] = -1;
        continue;
      }
      const int id = q[0];
      auto it = ids.lower_bound(id);
      int id1 = (it != end(ids)) ? *it : INT_MAX;
      int id2 = id1;
      if (it != begin(ids))
        id2 = *prev(it);
      ans[q[2]] = abs(id1 - id) < abs(id2 - id) ? id1 : id2;
    }
    return ans;
  }
};
