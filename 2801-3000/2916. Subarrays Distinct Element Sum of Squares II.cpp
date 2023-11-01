// https://www.bilibili.com/video/BV1Tz4y1N7Wx/?vd_source=48e4bed01dd155111c1b309b768743f6
// https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii/solutions/2502897/yi-bu-bu-ti-shi-ni-si-kao-ben-ti-pythonj-zhhs/
class Solution {
    vector<long long> sum;
    vector<int> todo;

    void do_(int o, int l, int r, int add) {
        sum[o] += (long long) add * (r - l + 1);
        todo[o] += add;
    }

    // o=1  [l,r] 1<=l<=r<=n
    // 把 [L,R] 加一，同时返回加一之前的区间和
    long long query_and_add1(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            long long res = sum[o];
            do_(o, l, r, 1);
            return res;
        }

        int m = (l + r) / 2;
        int add = todo[o];
        if (add != 0) {
            do_(o * 2, l, m, add);
            do_(o * 2 + 1, m + 1, r, add);
            todo[o] = 0;
        }

        long long res = 0;
        if (L <= m) res += query_and_add1(o * 2, l, m, L, R);
        if (m < R)  res += query_and_add1(o * 2 + 1, m + 1, r, L, R);
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
        return res;
    }

public:
    int sumCounts(vector<int> &nums) {
        int n = nums.size();
        sum.resize(n * 4);
        todo.resize(n * 4);

        long long ans = 0, s = 0;
        unordered_map<int, int> last;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int j = last.count(x) ? last[x] : 0;
            s += query_and_add1(1, 1, n, j + 1, i) * 2 + i - j;
            ans = (ans + s) % 1'000'000'007;
            last[x] = i;
        }
        return ans;
    }
};

