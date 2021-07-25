class Solution {
public:
    int getLucky(string s, int k) {
        int n = 0;
        for (char c : s) {
            auto num = to_string(c - 'a' + 1);
            for (char nc : num) n += nc - '0';
        }
        for (int i = 1; i < k; ++i) {
            int next = 0;
            while (n) {
                next += n % 10;
                n /= 10;
            }
            n = next;
        }
        return n;
    }
};
