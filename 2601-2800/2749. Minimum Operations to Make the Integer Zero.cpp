// https://leetcode.cn/problems/minimum-operations-to-make-the-integer-zero/solution/mei-ju-da-an-pythonjavacgo-by-endlessche-t4co/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= num1 - num2 * k; k++)
            if (k >= __builtin_popcountll(num1 - num2 * k))
                return k;
        return -1;
    }
};
