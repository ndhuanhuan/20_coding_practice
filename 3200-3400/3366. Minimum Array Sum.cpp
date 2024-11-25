// https://leetcode.cn/problems/minimum-array-sum/solutions/2998867/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-0pc5/
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector memo(n, vector(op1 + 1, vector<int>(op2 + 1, -1))); // -1 表示没有计算过
        auto dfs = [&](auto&& dfs, int i, int op1, int op2) -> int {
            if (i < 0) {
                return 0;
            }
            int& res = memo[i][op1][op2]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            int x = nums[i];
            res = dfs(dfs, i - 1, op1, op2) + x;
            if (op1) {
                res = min(res, dfs(dfs, i - 1, op1 - 1, op2) + (x + 1) / 2);
            }
            if (op2 && x >= k) {
                res = min(res, dfs(dfs, i - 1, op1, op2 - 1) + x - k);
                if (op1) {
                    int y = (x + 1) / 2 >= k ? (x + 1) / 2 - k : (x - k + 1) / 2;
                    res = min(res, dfs(dfs, i - 1, op1 - 1, op2 - 1) + y);
                }
            }
            return res;
        };
        return dfs(dfs, n - 1, op1, op2);
    }
};
