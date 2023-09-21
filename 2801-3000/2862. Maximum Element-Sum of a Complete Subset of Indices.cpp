// https://leetcode.cn/problems/maximum-element-sum-of-a-complete-subset-of-indices/solutions/2446037/an-zhao-corei-fen-zu-pythonjavacgo-by-en-i6nu/
class Solution {
public:
    long long maximumSum(vector<int> &nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            long long sum = 0;
            for (int j = 1; i * j * j <= n; j++) {
                sum += nums[i * j * j - 1]; // -1 是因为数组下标从 0 开始
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
