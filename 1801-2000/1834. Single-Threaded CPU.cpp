// https://zxi.mytechroad.com/blog/simulation/leetcode-1834-single-threaded-cpu/
class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    const int n = tasks.size();
    for (int i = 0; i < n; ++i)
      tasks[i].push_back(i);
    sort(begin(tasks), end(tasks)); // sort by enqueue_time;    
    
    vector<int> ans;
    priority_queue<pair<int, int>> q; // {-processing_time, -index}
    int i = 0;
    long t = 0;    
    while (ans.size() != n) {
      // Advance to next enqueue time if q is empty.
      if (i < n && q.empty() && tasks[i][0] > t)
        t = tasks[i][0];
      // Enqueue all available tasks.
      while (i < n && tasks[i][0] <= t) {
        q.emplace(-tasks[i][1], -tasks[i][2]);
        ++i;
      }
      // Extra the top one.
      t -= q.top().first;
      ans.push_back(-q.top().second);
      q.pop();      
    }
    return ans;
  }
};
