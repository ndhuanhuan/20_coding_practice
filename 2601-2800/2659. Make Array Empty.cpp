// https://leetcode.cn/problems/make-array-empty/solution/shu-zhuang-shu-zu-mo-ni-pythonjavacgo-by-ygvb/
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int> &nums) {
        int n = nums.size(), id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](int i, int j) { return nums[i] < nums[j]; });
        long long ans = n;
        for (int k = 1; k < n; ++k)
            if (id[k] < id[k - 1]) // 必须多走一整圈
                ans += n - k; // 减去前面删除的元素个数
        return ans;
    }
};
