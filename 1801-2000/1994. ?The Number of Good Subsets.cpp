// https://leetcode.com/problems/the-number-of-good-subsets/discuss/1445110/C%2B%2B-Bitmask-DP-solution-with-prime-factor-bitmask-precomputed
// https://leetcode.com/problems/the-number-of-good-subsets/discuss/1444647/C%2B%2B-or-DP-Bitmask-or-Time-O(30*-1lessless10)-Space-O(1lessless10)-or-club-togather
class Solution {
    int16_t map[31] = {
        // Primes
        [2] = 1,
        [3] = 2,
        [5] = 4,
        [7] = 8,
        [11] = 16,
        [13] = 32,
        [17] = 64,
        [19] = 128,
        [23] = 256,
        [29] = 512,
        
        // Others
        [6] = 3,
        [10] = 5,
        [14] = 9,
        [15] = 6,
        [21] = 10,
        [22] = 17,
        [26] = 33,
        [30] = 7,
    };
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n_ones = 0;
        
        for (int num : nums) {
            if (num == 1) {
                n_ones++;
            }
            if (map[num] == 0) {
                continue;
            }
            cnt[num]++;
        }
        vector<uint64_t> dp(1 << 10); 
        
        for (const auto& pair : cnt) {
            for (int16_t bits = (1 << 10) - 1; bits >= 0; bits--) {
                if ((map[pair.first] & bits) != map[pair.first]) {
                    continue;
                }
                dp[bits] += (dp[bits & ~map[pair.first]] + 1) * (uint64_t) pair.second;
                dp[bits] %= 1000000007;
            }
        }
            
        int result = dp[(1 << 10) - 1];
        while (n_ones--) {
            result *= 2;
            result %= 1000000007;
        }
        return result;
    }
};
