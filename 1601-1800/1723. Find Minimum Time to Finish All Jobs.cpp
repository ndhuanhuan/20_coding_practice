// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1723-find-minimum-time-to-finish-all-jobs/
class Solution {
public:
  int minimumTimeRequired(vector<int>& jobs, int k) {
    vector<int> times(k);
    int ans = INT_MAX;
    function<void(int, int)> dfs = [&](int i, int cur) {
      if (cur >= ans) return;
      if (i == jobs.size()) {
        ans = cur;
        return;
      }
      unordered_set<int> seen;
      for (int j = 0; j < k; ++j) {
        if (!seen.insert(times[j]).second) continue;
        times[j] += jobs[i];
        dfs(i + 1, max(cur, times[j]));
        times[j] -= jobs[i];
      }
    };
    sort(rbegin(jobs), rend(jobs));
    dfs(0, 0);
    return ans;
  }
};
