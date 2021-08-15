// fast power: https://www.rookieslab.com/posts/fast-power-algorithm-exponentiation-by-squaring-cpp-python-implementation
// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/discuss/1403912/C%2B%2B-Solution.-Fast-pow.
typedef long long ll;
ll M = 1000000007;
ll fast(ll a, ll b) {
    ll p = 1;
    a %= M;
    while(b) {
        if(b & 1) p *= a;
        a *= a;
        b = b >> 1;
        p %= M;
        a %= M;
    }
    return p % M;
}

class Solution{
public:
    int minNonZeroProduct(long long p) {
        long long mx = (1L << p) - 1;
        return fast(mx - 1, mx / 2) % M * (mx % M) % M;
    }
};
