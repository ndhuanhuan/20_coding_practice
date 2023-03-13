// https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/solution/tan-xin-pythonjavacgo-by-endlesscheng-w3k3/
class Solution {
    bool run[2001];
public:
    int findMinimumTime(vector<vector<int>> &tasks) {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int ans = 0;
        for (auto &t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            for (int i = start; i <= end; ++i)
                d -= run[i]; // 去掉运行中的时间点
            for (int i = end; d > 0; --i) // 剩余的 d 填充区间后缀
                if (!run[i]) {
                    run[i] = true;
                    --d;
                    ++ans;
                }
        }
        return ans;
    }
};

