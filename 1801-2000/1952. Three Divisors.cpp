class Solution {
public:
    bool isThree(int n) {
        int d = 2;
        for (int i = 2; i < n && d <= 3; i += 1)
            d += n % i == 0;
        return d == 3;
    }
};
