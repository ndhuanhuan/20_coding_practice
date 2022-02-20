// For a given number, only the gcd between current number num[i] and k need to be considered. 
// All we need to do is to count/group the numbers by the gcds. And if gcd(num[i], k) * gcd(num[j], k) is divisible by k , num[i] * num[j] should also be divisible.
// https://leetcode.com/problems/count-array-pairs-divisible-by-k/discuss/1784721/Count-GCDs-vs.-K-Factorization
// https://leetcode.com/problems/count-array-pairs-divisible-by-k/discuss/1784821/Java-Counting-previous-numbers-by-GCDs
class Solution {
public:
    long long coutPairs(vector<int>& n, int k) {
        long long res = 0;
        int cnt[100001] = {};
        vector<int> divs;
        for (int i = 1; i * i <= k; ++i) {
            if (k % i == 0) {
                divs.push_back(i);
                if (i * i < k)
                    divs.push_back(k / i);
            }
        }
        for (int i = 0; i < n.size(); ++i) {
            res += cnt[k / gcd(k, n[i])];
            for (auto j : divs)
                cnt[j] += n[i] % j == 0;
        }
        return res;
    }
};
