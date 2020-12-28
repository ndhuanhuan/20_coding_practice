// https://zxi.mytechroad.com/blog/priority-queue/leetcode-1705-maximum-number-of-eaten-apples/
class Solution {
public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    const int n = apples.size();
    using P = pair<int, int>;    
    priority_queue<P, vector<P>, greater<P>> q; // {rotten_day, index}    
    int ans = 0;
    for (int d = 0; d < n || !q.empty(); ++d) {
      if (d < n && apples[d]) q.emplace(d + days[d], d);
      while (!q.empty() 
             && (q.top().first <= d || apples[q.top().second] == 0)) q.pop();
      if (q.empty()) continue;
      --apples[q.top().second];      
      ++ans;
    }
    return ans;
  }
};
