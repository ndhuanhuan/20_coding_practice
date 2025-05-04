// https://leetcode.cn/problems/merge-operations-for-minimum-travel-time/solutions/3668454/hua-fen-xing-dpcong-ji-yi-hua-sou-suo-da-cref/
// (position[nxt] - position[i]) * t; 的理解
// (position[nxt] - position[i]) 这是由于下一段的长度也可以合并，所以这个长度不是(position[i+1] - position[i]). 然后这一段长度的每公里时间受到上一段合并的影响。
// 上一段的影响是t

class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> s(n); // 前缀和数组
        partial_sum(time.begin(), time.end() - 1, s.begin() + 1); // time[n-1] 用不到

        vector memo(k + 1, vector(n - 1, vector<int>(n - 1)));
        auto dfs = [&](this auto&& dfs, int left_k, int i, int pre) -> int {
            if (i == n - 1) {
                return left_k ? INT_MAX / 2 : 0;
            }
            int& res = memo[left_k][i][pre]; // 注意这里是引用
            if (res) {
                return res;
            }
            res = INT_MAX;
            int t = s[i + 1] - s[pre]; // 合并到 time[i] 的时间
            for (int nxt = i + 1; nxt < min(n, i + 2 + left_k); nxt++) {
                int r = dfs(left_k - (nxt - i - 1), nxt, i + 1) + (position[nxt] - position[i]) * t;
                res = min(res, r);
            }
            return res;
        };
        return dfs(k, 0, 0);
    }
};
