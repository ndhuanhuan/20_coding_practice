// https://leetcode.cn/problems/maximum-score-of-non-overlapping-intervals/solutions/3039058/dong-tai-gui-hua-er-fen-cha-zhao-you-hua-wmuy/
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        struct tuple { int l, r, weight, i; };
        vector<tuple> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        ranges::sort(a, {}, &tuple::r);

        vector<array<pair<long long, vector<int>>, 5>> f(n + 1);
        for (int i = 0; i < n; i++) {
            auto [l, r, weight, idx] = a[i];
            int k = lower_bound(a.begin(), a.begin() + i, l, [](tuple& t, int val) { return t.r < val; }) - a.begin();
            for (int j = 1; j < 5; j++) {
                long long s1 = f[i][j].first;
			    // 为什么是 f[k] 不是 f[k+1]：上面算的是 >= l，-1 后得到 < l，但由于还要 +1，抵消了
                long long s2 = f[k][j - 1].first + weight;
                if (s1 > s2) {
                    f[i + 1][j] = f[i][j];
                    continue;
                }
                vector<int> new_id = f[k][j - 1].second;
                new_id.push_back(idx);
                ranges::sort(new_id);
                if (s1 == s2 && f[i][j].second < new_id) {
                    new_id = f[i][j].second;
                }
                f[i + 1][j] = {s2, new_id};
            }
        }
        return f[n][4].second;
    }
};
