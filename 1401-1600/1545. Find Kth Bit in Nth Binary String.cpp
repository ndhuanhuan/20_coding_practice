// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/discuss/781181/JavaC%2B%2BPython-Iterative-Solutions
class Solution {
public:
   char findKthBit(int n, int k) {
        int flip = 0, l = (1 << n) - 1;
        while (k > 1) {
            if (k == l / 2 + 1)
                return '0' + (flip ^ 1);
            if (k > l / 2) {
                k = l + 1 - k;
                flip ^= 1;
            }
            l /= 2;
        }
        return '0' + flip;
    }
};
