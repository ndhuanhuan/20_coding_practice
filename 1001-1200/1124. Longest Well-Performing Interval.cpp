// https://zxi.mytechroad.com/blog/uncategorized/leetcode-1124-longest-well-performing-interval/
class Solution {
public:
  int longestWPI(vector<int>& hours) {
    const int n = hours.size();
    for (int& v : hours) v = v > 8 ? 1 : -1;
    int s = 0;
    unordered_map<int, int> idx;    
    int ans = 0;
    for (int i = 0; i < hours.size(); ++i) {
      s += hours[i];
      if (s > 0) 
        ans = i + 1;
      if (!idx.count(s)) 
        idx[s] = i;
      if (idx.count(s - 1))
        ans = max(ans, i - idx[s - 1]);
    }
    return ans;
  }
};
