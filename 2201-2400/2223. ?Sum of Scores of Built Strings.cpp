// https://www.bilibili.com/video/BV1Pa4y147Qn?spm_id_from=333.337.search-card.all.click
// https://www.scaler.com/topics/data-structures/z-algorithm/
// https://leetcode.com/problems/sum-of-scores-of-built-strings/discuss/1907066/C%2B%2B-or-Z-Function-or-Resources-to-learn
class Solution
{
    public:
        long long z_function(string s)
        {
            int n = (int) s.length();
            vector < long long > z(n);
            for (int i = 1, l = 0, r = 0; i < n; ++i)
            {
                if (i <= r)
                    z[i] = min((r - i + 1) *1LL, z[i - l]);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                    ++z[i];
                if (i + z[i] - 1 > r)
                    l = i, r = i + z[i] - 1;
            }
            long long sum = 0;
            for (auto xt: z)
                sum += xt;
            return sum;
        }
    long long sumScores(string s)
    {
        return 1LL*s.size() + z_function(s);
    }
};
