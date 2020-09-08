// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830480/C%2B%2B-O(N)-Sliding-window-Explanation-with-Illustrations
// https://zxi.mytechroad.com/blog/two-pointers/leetcode-1574-shortest-subarray-to-be-removed-to-make-array-sorted/
class Solution {
public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    const int n = arr.size();
    int j = n - 1;
    while (j > 0 && arr[j - 1] <= arr[j]) --j;
    if (j == 0) return 0;
    int ans = j; // remove arr[0~j-1]
    for (int i = 0; i < n; ++i) {
      if (i > 0 && arr[i - 1] > arr[i]) break;
      while (j < n && arr[i] > arr[j]) ++j;      
      // arr[i] <= arr[j], remove arr[i + 1 ~ j - 1]
      ans = min(ans, j - i - 1);
    }
    return ans;
  }
};
