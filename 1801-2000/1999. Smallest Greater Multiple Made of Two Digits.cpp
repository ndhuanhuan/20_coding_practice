// https://leetcode.com/problems/smallest-greater-multiple-made-of-two-digits/discuss/1454948/Simple-Search
class Solution {
public:
    int findInteger(int k, int digit1, int digit2, long long x = 0) {
        if (x > INT_MAX) return -1;
        if (isValid(x, k)) return x;
        int x1 = (x + digit1== 0) ? -1 : findInteger(k, digit1, digit2, x*10 + digit1);
        int x2 = (x + digit2== 0) ? -1 : findInteger(k, digit1, digit2, x*10 + digit2);
        return x1 > 1 && x2 > 1 ? min(x1, x2) : max(x1, x2);
    }
    
private:
    bool isValid(int num, int k) {
        if(num%k == 0 && num > k) return true;
        return false;
    }
};
