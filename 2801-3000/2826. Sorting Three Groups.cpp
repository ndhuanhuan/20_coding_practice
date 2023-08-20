// https://leetcode.cn/problems/sorting-three-groups/solutions/2396466/liang-chong-fei-bao-li-zuo-fa-liszhuang-38zac/
class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        int f[4]{};
        for (int x: nums)
            for (int j = 3; j; j--)
                f[j] = *min_element(f + 1, f + j + 1) + (j != x);
        return *min_element(f + 1, f + 4);
    }
};

