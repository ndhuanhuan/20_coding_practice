// https://leetcode.cn/problems/maximum-xor-score-subarray-queries/solutions/2899932/qu-jian-dp-tao-qu-jian-dppythonjavacgo-b-w4be/
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        vector<vector<int>> mx(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            f[i][i] = nums[i];
            mx[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                f[i][j] = f[i][j - 1] ^ f[i + 1][j];
                mx[i][j] = max({f[i][j], mx[i + 1][j], mx[i][j - 1]});
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(mx[q[0]][q[1]]);
        }
        return ans;
    }
};

