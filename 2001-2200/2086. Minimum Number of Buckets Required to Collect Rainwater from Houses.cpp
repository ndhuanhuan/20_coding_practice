// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/discuss/1599341/Greedy
class Solution {
public:
    int minimumBuckets(string st) {
        for (int i = 0; i < st.size(); ++i) {
            if (st[i] == 'H') {
                if (i > 0 && st[i - 1] == 'B')
                    continue;
                if (i < st.size() - 1 && st[i + 1] == '.')
                    st[i + 1] = 'B';
                else if (i > 0 && st[i - 1] == '.')
                    st[i - 1] = 'B';
                else
                    return -1;
            }
        }
        return count(begin(st), end(st), 'B');
    }
};
