// https://leetcode.cn/problems/two-letter-card-game/solutions/3768070/mei-ju-jie-lun-pythonjavacgo-by-endlessc-zbnv/
class Solution {
    // 计算除了 x 以外的出现次数之和 sum，出现次数最大值 mx
    pair<int, int> get_sum_and_max(const array<int, 10>& cnt, char x) {
        int sum = 0, mx = 0;
        for (int i = 0; i < cnt.size(); i++) {
            if (i != x - 'a') {
                sum += cnt[i];
                mx = max(mx, cnt[i]);
            }
        }
        return {sum, mx};
    }

    // 计算这一组在得到 k 个 xx 后的得分
    int calc_score(int sum, int mx, int k) {
        sum += k;
        mx = max(mx, k);
        return min(sum / 2, sum - mx);
    }

public:
    int score(vector<string>& cards, char x) {
        array<int, 10> cnt1{}, cnt2{}; // 题目保证只有前 10 个小写字母
        for (auto& s : cards) {
            // 统计形如 x? 的每个 ? 的出现次数
            if (s[0] == x) {
                cnt1[s[1] - 'a']++;
            }
            // 统计形如 ?x 的每个 ? 的出现次数
            if (s[1] == x) {
                cnt2[s[0] - 'a']++;
            }
        }

        auto [sum1, max1] = get_sum_and_max(cnt1, x);
        auto [sum2, max2] = get_sum_and_max(cnt2, x);

        int cnt_xx = cnt1[x - 'a'];
        int ans = 0;
        // 枚举分配 k 个 xx 给第一组，其余的 xx 给第二组
        for (int k = 0; k <= cnt_xx; k++) {
            int score1 = calc_score(sum1, max1, k);
            int score2 = calc_score(sum2, max2, cnt_xx - k);
            ans = max(ans, score1 + score2);
        }
        return ans;
    }
};
