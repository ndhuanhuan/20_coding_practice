// https://zxi.mytechroad.com/blog/hashtable/leetcode-1604-alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
class Solution {
public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    unordered_map<string, vector<int>> t; // {name -> time}
    for (size_t i = 0; i < keyName.size(); ++i) {
      const int h = stoi(keyTime[i].substr(0, 2));
      const int m = stoi(keyTime[i].substr(3));
      t[keyName[i]].push_back(h * 60 + m);
    }
    vector<string> ans;
    for (auto& [name, times] : t) {
      sort(begin(times), end(times));
      for (size_t i = 2; i < times.size(); ++i)
        if (times[i] - times[i - 2] <= 60) {
          ans.push_back(name);
          break;
        }   
    }
    sort(begin(ans), end(ans));
    return ans;
  }
};
