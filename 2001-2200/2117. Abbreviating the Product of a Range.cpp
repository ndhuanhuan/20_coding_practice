// https://leetcode.com/problems/abbreviating-the-product-of-a-range/discuss/1647115/Modulo-and-Double
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long suff = 1, c = 0, total = 0, max_suff = 100000000000;
        double pref = 1.0, max_pref = 10000;
        bool over = false;
        for (int i = left; i <= right; ++i) {
            pref *= i;
            suff *= i;
            while (pref >= 100000) {
                pref /= 10;
                total = total == 0 ? 5 : total + 1; 
            }
            while (suff % 10 == 0) {
                suff /= 10;
                ++c;
            }
            suff %= max_suff;
        }
        string s = to_string(suff);
        return (total - c <= 10 ? s : to_string((int)pref) + "..." + s.substr(s.size() - 5)) + "e" + to_string(c);
    }
};
