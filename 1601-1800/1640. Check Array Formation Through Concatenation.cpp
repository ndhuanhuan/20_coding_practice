// https://zxi.mytechroad.com/blog/hashtable/leetcode-1640-check-array-formation-through-concatenation/
class Solution {
public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int, int> m;
    for (int i = 0; i < pieces.size(); ++i)
      m[pieces[i][0]] = i;
    
    vector<int> ans;
    for (int a : arr) {
      if (!m.count(a)) continue;
      ans.insert(end(ans), begin(pieces[m[a]]), end(pieces[m[a]]));
    }
    
    return ans == arr;
  }
};
