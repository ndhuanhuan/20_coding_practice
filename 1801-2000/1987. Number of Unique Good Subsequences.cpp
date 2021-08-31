// https://leetcode.com/problems/number-of-unique-good-subsequences/discuss/1431819/JavaC%2B%2BPython-DP-4-lines-O(N)-Time-O(1)-Space
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod = 1e9 + 7, dp[2] = {0, 0};
        for (char& c: binary)
            dp[c - '0'] = (dp[0] + dp[1] + c - '0') % mod;
        return (dp[0] + dp[1] + (binary.find("0") != string::npos)) % mod;
    }
};
