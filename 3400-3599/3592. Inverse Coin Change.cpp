// https://leetcode.cn/problems/inverse-coin-change/solutions/3705647/wan-quan-bei-bao-pythonjavacgo-by-endles-y6oq/
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> f(n + 1);
        f[0] = 1;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int ways = numWays[i - 1];
            if (ways == f[i]) {
                continue;
            }
            if (ways - 1 != f[i]) {
                return {};
            }
            ans.push_back(i);
            // 现在得到了一个大小为 i 的物品，用 i 计算完全背包（空间优化写法）
            for (int j = i; j <= n; j++) {
                f[j] += f[j - i];
            }
        }
        return ans;
    }
};
