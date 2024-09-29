// https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/solutions/2934309/liang-ci-hua-chuang-pythonjavacgo-by-end-2lpz/
class Solution {
    const string VOWEL = "aeiou";

    long long f(string& word, int k) {
        long long ans = 0;
        // 这里用哈希表实现，替换成数组会更快
        unordered_map<char, int> cnt1; // 每种元音的个数
        int cnt2 = 0; // 辅音个数
        int left = 0;
        for (char b : word) {
            if (VOWEL.find(b) != string::npos) {
                cnt1[b]++;
            } else {
                cnt2++;
            }
            while (cnt1.size() == 5 && cnt2 >= k) {
                char out = word[left];
                if (VOWEL.find(out) != string::npos) {
                    if (--cnt1[out] == 0) {
                        cnt1.erase(out);
                    }
                } else {
                    cnt2--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k + 1);
    }
};
