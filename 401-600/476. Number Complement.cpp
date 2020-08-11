// https://zxi.mytechroad.com/blog/bit/476-number-complement/
class Solution {
public:
    int findComplement(int num) {
        size_t mask = ~0;
        while(num & mask) mask <<= 1;
        return ~num ^ mask;
    }
};
