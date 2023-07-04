// https://leetcode.cn/problems/sum-of-imbalance-numbers-of-all-subarrays/solution/bao-li-mei-ju-pythonjavacgo-by-endlessch-2r7p/
class Solution {
public:
    int sumImbalanceNumbers(vector<int> &nums) {
        int ans = 0, n = nums.size();
        bool vis[n + 2];
        for (int i = 0; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            vis[nums[i]] = true;
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                int x = nums[j];
                if (!vis[x]) {
                    cnt += 1 - vis[x - 1] - vis[x + 1];
                    vis[x] = true;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};

