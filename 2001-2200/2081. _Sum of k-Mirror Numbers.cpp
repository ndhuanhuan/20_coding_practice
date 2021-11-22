// https://leetcode.com/problems/sum-of-k-mirror-numbers/discuss/1589683/C%2B%2B-Enumerate-palindromes
class Solution {
public:
    long long get_palin_num(long long num, bool odd) {
        long long x = num;
        if (odd) x /= 10;
        
        while (x) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }
    
    string to_base(long long num, int &base) {
        string res = "";
        while (num) {
            res += num % base + '0';
            num /= base;
        }
        return res;
    }
    
    bool is_palin(long long &num, int &base) {
        string s = to_base(num, base);
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
    
    long long kMirror(int k, int n) {
        long long sum = 0, num = 0;
        for (long long num_digit=1; n; num_digit*=10) {
            // odd number of digits
            for (long long cur=num_digit; n && cur < num_digit*10; ++cur) {
                num = get_palin_num(cur, true);
                if (is_palin(num, k)) {
                    sum += num;
                    --n;
                }
            }
            // even number of digits
            for (long long cur=num_digit; n && cur < num_digit*10; ++cur) {
                num = get_palin_num(cur, false);
                if (is_palin(num, k)) {
                    sum += num;
                    --n;
                }
            }
        }
        return sum;
    }
};


// https://leetcode.com/problems/sum-of-k-mirror-numbers/discuss/1589104/Brute-Force
class Solution {
public:
vector<long long> mirror1{0}, mirror2{0};
long long isMirror(long long num, int base) {
    long long mul = 1;
    while (mul * base <= num)
        mul *= base;
    for (; num; mul /= base * base) {
        if (num / mul != num % base)
            return false;
        num = (num - (num / mul) * mul - num % base) / base;
    }
    return true;
}
long long generate(int dig, int n, int k, long long first_mul) {
    vector<long long> mirror;
    long long res = 0;
    for (int i = 0; n > 0 && i < 10; ++i)
        for (int j = 0; n > 0 && j < mirror1.size(); ++j) {
            mirror.push_back(first_mul * i + mirror1[j] * 10 + i); 
            if (i != 0 && isMirror(mirror.back(), k)) {
                res += mirror.back();
                --n;
            }
        }
    swap(mirror1, mirror2);
    swap(mirror2, mirror);
    return res + (n == 0 ? 0 : generate(dig + 1, n, k, first_mul * 10));
}
long long kMirror(int k, int n) {
    long long res = 0;
    for (int i = 1; n > 0 && i < 10; ++i) {
        mirror2.push_back(i);
        if (isMirror(i, k)) {
            res += i;
            --n;
        }
    }
    return res + generate(2, n, k, 10);
}
};
