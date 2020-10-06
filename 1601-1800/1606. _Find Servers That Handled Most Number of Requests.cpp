// https://zxi.mytechroad.com/blog/simulation/leetcode-1606-find-servers-that-handled-most-number-of-requests/
class Solution {
public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> q; // {release_time, server}
    set<int> servers;
    vector<int> requests(k);
    
    for (int i = 0; i < k; ++i)
      servers.insert(i);
    
    for (int i = 0; i < arrival.size(); ++i) {
      const int t = arrival[i];
      const int l = load[i];
      
      // Release servers. O(logk) per pop()
      while (!q.empty() && q.top().first <= t) {        
        servers.insert(q.top().second);  
        q.pop();
      }
      
      // Drop the request.
      if (servers.empty()) continue;
      
      // Find first avaiable one O(logk)
      auto it = servers.lower_bound(i % k);
      if (it == servers.end()) it = begin(servers);
      const int idx = *it;
      
      ++requests[idx];
      servers.erase(it);
      q.emplace(t + l, idx);
    }
    const int max_req = *max_element(begin(requests), end(requests));
    vector<int> ans;
    for (int i = 0; i < k; ++i)
      if (requests[i] == max_req) ans.push_back(i);
    return ans;
  }
};
