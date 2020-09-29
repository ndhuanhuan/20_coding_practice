// https://zxi.mytechroad.com/blog/simulation/leetcode-1598-crawler-log-folder/
class Solution {
public:
  int minOperations(vector<string>& logs) {
    int ans = 0;
    for (const string& log : logs) {
      if (log == "../")
        ans = max(ans - 1, 0);
      else if (log != "./")
        ++ans;
    }
    return ans;
  }
};
