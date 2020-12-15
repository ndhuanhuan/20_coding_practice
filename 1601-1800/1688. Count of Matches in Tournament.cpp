// https://zxi.mytechroad.com/blog/simulation/leetcode-1688-count-of-matches-in-tournament/
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n > 1) {
            res += n / 2 + (n & 1);
            n /= 2;
        }
        return res;
    }
};
