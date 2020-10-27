// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1629-slowest-key/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int l = releaseTimes[0];
          char ans = keysPressed[0];
          for (int i = 1; i < releaseTimes.size(); ++i) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if (t > l) {
              ans = keysPressed[i];
              l = t;
            } else if (t == l) {
              ans = max(ans, keysPressed[i]);
            }
          }
          return ans;
    }
};

