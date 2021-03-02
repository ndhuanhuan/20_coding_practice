// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1773-count-items-matching-a-rule/
class Solution {
public:
  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    return count_if(begin(items), end(items), [&](const auto& item) {
      return (ruleKey == "type" && item[0] == ruleValue
        || ruleKey == "color" && item[1] == ruleValue
        || ruleKey == "name" && item[2] == ruleValue);
    });    
  }
};
