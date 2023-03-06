// https://leetcode.cn/problems/split-the-array-to-make-coprime-products/solution/ben-zhi-shi-tiao-yue-you-xi-by-endlessch-8chd/
class Solution {
public:
    int findValidSplit(vector<int> &nums) {
        unordered_map<int, int> left; // left[p] 表示质数 p 首次出现的下标
        int n = nums.size(), right[n]; // right[i] 表示左端点为 i 的区间的右端点的最大值
        memset(right, 0, sizeof(right));
        auto f = [&](int p, int i) {
            auto it = left.find(p);
            if (it == left.end())
                left[p] = i; // 第一次遇到质数 p
            else
                right[it->second] = i; // 记录左端点 l 对应的右端点的最大值
        };

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int d = 2; d * d <= x; ++d) { // 分解质因数
                if (x % d == 0) {
                    f(d, i);
                    for (x /= d; x % d == 0; x /= d);
                }
            }
            if (x > 1) f(x, i);
        }

        for (int l = 0, max_r = 0; l < n; ++l) {
            if (l > max_r) // 最远可以遇到 max_r
                return max_r; // 也可以写 l-1
            max_r = max(max_r, right[l]);
        }
        return -1;
    }
};
