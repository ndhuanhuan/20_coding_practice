// https://leetcode.com/problems/number-of-wonderful-substrings/discuss/1299523/C%2B%2B-Bit-Vector-%2B-Prefix-Parities-(Similar-to-Prefix-Sums)
// https://leetcode.com/problems/number-of-wonderful-substrings/discuss/1299525/Count-bitmasks-with-picture

// 只有两种可能
// Case 1: 两个之间夹杂了一个字母都是偶数cnt的string
// 0001 =>a
// 0001 =>abb
// 0001 => abbbb
// bb, bb, bbbb, 就是candidates
// 对应代码： res += cnt[mask];
// Case 2: 两个之间夹杂了一个字母都是偶数cnt的string, 除了某一位是奇数
// 0001 =>a
// (代码 1 << n )0010 
// 0001 ^ 0010 = 0011 => ab
// 也就是说找0001 和 0011 之间的wonderful string，可以知道这俩之间夹杂着cnt[mask ^ (1 << n)] 个 b为奇数，其它字母为偶数的candidates。
// b 就是一个candidate。 
// case 2 稍难理解
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long cnt[1024] = { 1 }, mask = 0, res = 0;
        for (auto ch : word) {
            mask ^= 1 << (ch - 'a');
            res += cnt[mask];
            for (auto n = 0; n < 10; ++n)
                res += cnt[mask ^ (1 << n)];
            ++cnt[mask];
        }
        return res;
    }
};
