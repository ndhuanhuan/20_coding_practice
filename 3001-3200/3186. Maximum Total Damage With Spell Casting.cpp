// class Solution {
// public:
//     long long maximumTotalDamage(vector<int>& power) {
//         unordered_map<int, int> cnt;
//         for (int x : power) {
//             cnt[x]++;
//         }

//         vector<pair<int, int>> a(cnt.begin(), cnt.end());
//         ranges::sort(a);

//         int n = a.size();
//         vector<long long> memo(n, -1);
//         auto dfs = [&](auto&& dfs, int i) -> long long {
//             if (i < 0) {
//                 return 0;
//             }
//             long long& res = memo[i]; // 注意这里是引用
//             if (res != -1) {
//                 return res;
//             }
//             auto& [x, c] = a[i];
//             int j = i;
//             while (j && a[j - 1].first >= x - 2) {
//                 j--;
//             }
//             return res = max(dfs(dfs, i - 1), dfs(dfs, j - 1) + (long long) x * c);
//         };
//         return dfs(dfs, n - 1);
//     }
// };


class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for (int x : power) {
            cnt[x]++;
        }

        vector<pair<int, int>> a(cnt.begin(), cnt.end());
        ranges::sort(a);

        int n = a.size();
        vector<long long> f(n + 1);
        for (int i = 0, j = 0; i < n; i++) {
            auto& [x, c] = a[i];
            while (a[j].first < x - 2) {
                j++;
            }
            f[i + 1] = max(f[i], f[j] + (long long) x * c);
        }
        return f[n];
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/solutions/2812389/tao-lu-da-jia-jie-she-pythonjavacgo-by-e-p9b5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
