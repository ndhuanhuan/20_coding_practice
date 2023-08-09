// https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/solution/fan-hui-tan-xin-pythonjavacgo-by-endless-v2w1
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>> &items, int k) {
        // 把利润从大到小排序
        sort(items.begin(), items.end(), [](const auto &a, const auto &b) {
            return a[0] > b[0];
        });
        long long ans = 0, total_profit = 0;
        unordered_set<int> vis;
        stack<int> duplicate; // 重复类别的利润
        for (int i = 0; i < items.size(); i++) {
            int profit = items[i][0], category = items[i][1];
            if (i < k) {
                total_profit += profit;
                if (!vis.insert(category).second) // 重复类别
                    duplicate.push(profit);
            } else if (!duplicate.empty() && vis.insert(category).second) {
                total_profit += profit - duplicate.top(); // 选一个重复类别中的最小利润替换
                duplicate.pop();
            } // else：比前面的利润小，而且类别还重复了，选它只会让 totalProfit 变小，vis.size() 不变，优雅度不会变大
            ans = max(ans, total_profit + (long long) vis.size() * (long long) vis.size());
        }
        return ans;
    }
};

