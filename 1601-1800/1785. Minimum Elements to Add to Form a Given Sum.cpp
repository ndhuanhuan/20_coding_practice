// https://zxi.mytechroad.com/blog/math/leetcode-1785-minimum-elements-to-add-to-form-a-given-sum/
class Solution {
public:
  int minElements(vector<int>& nums, int limit, int goal) {
    int64_t diff = abs(goal - 
                       accumulate(begin(nums), end(nums), 0LL));
    return (diff + limit - 1) / limit;
  }
};
