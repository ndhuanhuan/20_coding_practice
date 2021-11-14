// https://leetcode.com/problems/decode-the-slanted-ciphertext/discuss/1576914/Jump-Columns-%2B-1
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int sz = encodedText.size(), cols = sz / rows;
        string res;
        for (int i = 0; i < cols; ++i)
            for (int j = i; j < sz; j += cols + 1)
                res += encodedText[j];
        while (!res.empty() && isspace(res.back()))
            res.pop_back();
        return res;
    }
};
