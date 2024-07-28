//https://leetcode.cn/problems/count-the-number-of-substrings-with-dominant-ones/solutions/2860198/mei-ju-zi-chuan-zhong-de-0-de-ge-shu-pyt-c654/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                a.push_back(i);
            }
        }

        int tot1 = n - a.size();
        a.push_back(n); // 哨兵

        int ans = 0, i = 0; // >= left 的第一个 0 的下标是 a[i]
        for (int left = 0; left < n; left++) {
            if (s[left] == '1') {
                ans += a[i] - left; // 不含 0 的子串个数
            }
            for (int k = i; k < a.size() - 1; k++) {
                int cnt0 = k - i + 1;
                if (cnt0 * cnt0 > tot1) {
                    break;
                }
                int cnt1 = a[k] - left - (k - i);
                ans += max(a[k + 1] - a[k] - max(cnt0 * cnt0 - cnt1, 0), 0);
            }
            if (s[left] == '0') {
                i++; // 这个 0 后面不会再枚举到了
            }
        }
        return ans;
    }
};

