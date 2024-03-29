
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> maxd, mind;
        int res = 0;
        int i = 0, j;
        for (j = 0; j < A.size(); ++j) {
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            maxd.push_back(A[j]);
            mind.push_back(A[j]);
            while (maxd.front() - mind.front() > limit) {
                if (maxd.front() == A[i]) maxd.pop_front();
                if (mind.front() == A[i]) mind.pop_front();
                ++i;
            }
            
            res = max(res, j - i + 1);
        }
        return res;
    }
};



// https://zxi.mytechroad.com/blog/queue/leetcode-1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    deque<int> max_q;
    deque<int> min_q;
    int ans = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
      while (!min_q.empty() && nums[r] < min_q.back()) 
        min_q.pop_back();
      while (!max_q.empty() && nums[r] > max_q.back()) 
        max_q.pop_back();
      min_q.push_back(nums[r]);
      max_q.push_back(nums[r]);
      while (max_q.front() - min_q.front() > limit) {
        if (max_q.front() == nums[l]) max_q.pop_front();
        if (min_q.front() == nums[l]) min_q.pop_front();
        ++l;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
