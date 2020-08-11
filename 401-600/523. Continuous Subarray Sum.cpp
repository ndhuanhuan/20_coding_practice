// https://zxi.mytechroad.com/blog/hashtable/leetcode-523-continuous-subarray-sum/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for(int i =0; i < nums.size(); ++i) {
          sum += nums[i];
          if (k != 0) sum %= k;      
          if (m.count(sum)) {
            if (i - m.at(sum) > 1) return true;
          } else {
            m[sum] = i;
          }
        }
        
        return false;
    }
};
