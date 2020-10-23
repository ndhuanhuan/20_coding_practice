
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string s, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int l = -1, r = fonts.size() - 1, cnts[26] = {};
        for (auto ch : s)
            ++cnts[ch - 'a'];
        while (l < r) {
            int m = max(l + 1, (l + r) / 2), i = 0;
            if (fontInfo.getHeight(fonts[m]) > h || accumulate(begin(cnts), end(cnts), 0, [&](int t, int cnt)
                { return t + cnt * fontInfo.getWidth(fonts[m], 'a' + i++); }) > w)
                r = m - 1;
            else
                l = m;
        }
        return l == -1 ? -1 : fonts[l];
    }
};
