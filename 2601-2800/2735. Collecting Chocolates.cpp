// https://leetcode.cn/problems/collecting-chocolates/solution/qiao-miao-mei-ju-pythonjavacgo-by-endles-5ws2/
class Solution {
public:
    long long minCost(vector<int> &nums, int x) {
        int n = nums.size();
        long long sum[n];
        for (int i = 0; i < n; i++)
            sum[i] = (long long) i * x; // 操作 i 次
        for (int i = 0; i < n; i++) { // 子数组左端点
            int mn = nums[i];
            for (int j = i; j < n + i; j++) { // 子数组右端点（把数组视作环形的）
                mn = min(mn, nums[j % n]); // 从 nums[i] 到 nums[j%n] 的最小值
                sum[j - i] += mn; // 累加操作 j-i 次的成本
            }
        }
        return *min_element(sum, sum + n);
    }
};

